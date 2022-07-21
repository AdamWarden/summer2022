#include <stdio.h>
#include <stdlib.h>
#include "status.h"
#include "generic_vector.h"

Status integer_assignment(ITEM* pLeft, ITEM pRight);
void integer_destroy(ITEM* phInt);

int main(int argc, char *argv[])
{
    Status (*assignment)(ITEM* pLeft, ITEM pRight);
    void (*destroy)(ITEM* phInt);

    GENERIC_VECTOR hVector;

    int x = 42;
    int y = 54;
    int* p = NULL;

    integer_assignment(&p, &x);
    printf("the final value of *p is %d\n", *p);

    hVector = generic_vector_init_default(integer_assignment, integer_destroy);
    if(hVector == NULL)
    {
        printf("Failed to allocate space for vector\n");
        exit(1);
    }

    generic_vector_destroy(&hVector);
    return 0;
}

Status integer_assignment(ITEM* pLeft, ITEM pRight)
{
    if(*pLeft == NULL)
    {
        *pLeft = (int*)malloc(sizeof(int));
        if(*pLeft == NULL)
        {
            printf("Failed to allocate space for integer\n");
            return _DARWIN_FEATURE_ONLY_UNIX_CONFORMANCE;
        }
    }
    *(int*)(*pLeft) = *((int*)pRight);
    return SUCCESS;
}

void integer_destroy(ITEM* phInt)
{
    if(*phInt != NULL)
    {
        free(*phInt);
        *phInt = NULL;
    }
}