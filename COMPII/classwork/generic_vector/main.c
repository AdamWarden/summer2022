#include <stdio.h>
#include <stdlib.h>
#include "generic_vector.h"

Status integer_assignment(ITEM* phLeft, ITEM hRight);
void integer_destroy(ITEM* phItem);

int main(int argc, char* argv[])
{
	GENERIC_VECTOR hVector;
	int number;
	int i;

	hVector = generic_vector_init_default(integer_assignment, integer_destroy);

	if (hVector == NULL)
	{
		printf("Failed to allocate space for generic vector object.\n");
		exit(1);
	}
	number = 7;
	if (!generic_vector_push_back(hVector, &number))
	{
		printf("Failed to push_back 7\n");
	}
	else
	{
		printf("Successfully pushed back 7 into the generic vector.\n");
	}
	number = 8;
	if (!generic_vector_push_back(hVector, &number))
	{
		printf("Failed to push_back 8\n");
	}
	else
	{
		printf("Successfully pushed back 8 into the generic vector.\n");
	}

	printf("%d/%d\n", generic_vector_get_size(hVector), generic_vector_get_capacity(hVector));


	for (i = 0; i < generic_vector_get_size(hVector); i++)
	{
		printf("%d\n", *((int*)(*generic_vector_at(hVector, i))));
	}

	generic_vector_pop_back(hVector);
	printf("%d/%d\n", generic_vector_get_size(hVector), generic_vector_get_capacity(hVector));

	generic_vector_pop_back(hVector);
	printf("%d/%d\n", generic_vector_get_size(hVector), generic_vector_get_capacity(hVector));

	if (generic_vector_pop_back(hVector))
	{
		printf("Why did this work?\n");
	}
	else
	{
		printf("Failed as expected...\n");
	}
	generic_vector_destroy(&hVector);
	
	return 0;
}

Status integer_assignment(ITEM* phLeft, ITEM hRight)
{
	
	int* pLeft = (int*) *phLeft;
	int* pRight = (int*) hRight;
	if (pLeft == NULL)
	{
		pLeft = (int*)malloc(sizeof(int));
		if (pLeft == NULL)
		{
			return FAILURE;
		}
		*phLeft = pLeft;
	}

	*pLeft = *pRight;	
	return SUCCESS;
}

void integer_destroy(ITEM* phItem)
{
	int* pInt = *phItem;

	free(pInt);
}