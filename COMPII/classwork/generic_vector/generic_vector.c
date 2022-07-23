#include <stdio.h>
#include <stdlib.h>
#include "generic_vector.h"

typedef void* GENERIC_VECTOR;

GENERIC_VECTOR generic_vector_init_default(Status (*assignment)(ITEM* pLeft, ITEM pRight), void (*destroy)(ITEM* phInt))
{
    return NULL;
}
Boolean generic_vector_is_empty(GENERIC_VECTOR hVector)
{
    Generic_vector* pVector = (Generic_vector*)hVector;
    return (Boolean)(pVector->size <= 0);
}
Status generic_vector_push_back(GENERIC_VECTOR hVector, ITEM pItem)
{
    Generic_vector* pVector = (Generic_vector*)hVector;
    ITEM* temp;
    if(pVector->size >= pVector->capacity)
    {
        pVector->capacity *= 2;
        temp = (ITEM*)realloc(pVector->pItems, pVector->capacity * sizeof(ITEM));
        if(temp == NULL)
        {
            printf("Failed to allocate space for vector\n");
            exit(1);
        }
        for(int i = 0; i < pVector->size; i++)
        {
            temp[i] = pVector->pItems[i];
        }
        for(int i = pVector->size; i < pVector->capacity; i++)
        {
            temp[i] = NULL;
        }
        free(pVector->pItems);
        pVector->pItems = temp;
        pVector->capacity *=2;
    }
    pVector->pItems[pVector->size] = pItem;
    pVector->size++;
    return FAILURE;
}
Status generic_vector_pop_back(GENERIC_VECTOR hVector)
{
    return FAILURE;
}
int generic_vector_size(GENERIC_VECTOR hVector)
{
    return 0;
}
int generic_vector_capacity(GENERIC_VECTOR hVector)
{
    return 0;
}

ITEM* generic_vector_at(GENERIC_VECTOR hVector, int index)
{
    return NULL;
}

generic_vector_destroy(GENERIC_VECTOR* phVector)
{
    Generic_vector* pVector = (Generic_vector*)*phVector;
    int i;
    for(i = 0; i < pVector->size; i++)
    {
        pVector->item_destroy(pVector->data + i);
    }
    free(pVector->data);
    free(pVector);
    *phVector = NULL;
}