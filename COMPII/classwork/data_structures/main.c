#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "status.h"

int main(int argc, char* argv[])
{
	STACK hStack;

	hStack = stack_init_default();
	//initilize the stack
	if (hStack == NULL)
	{
		printf("Failed to allocate space for stack object.\n");
		exit(1);
	}

	//add to the stack
	stack_push(hStack, 10);
	stack_push(hStack, 2);
	stack_push(hStack, 3);
	printf("\n");

	while(!stack_is_empty(hStack))
	{
		printf("Found %d on the stack\n", stack_top(hStack, NULL));
		printf("Removed %d from the stack\n", stack_pop(hStack));
	}
	/*
	while(hStack != NULL)
	{
		stack_top(hStack, NULL);
		stack_pop(hStack);
	}
	*/
	stack_destroy(&hStack);
	
	return 0;
}