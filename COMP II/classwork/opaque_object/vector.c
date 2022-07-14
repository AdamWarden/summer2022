#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

//known type
struct vector
{
    int* data;
    int capacity;
    int size;
};

typedef struct vector Vector;

VECTOR vector_init_default(void){

    Vector* pVector = (Vector*)malloc(sizeof(Vector));
    if(pVector != NULL){
        pVector->size = 0;
        pVector->capacity = 1;
        pVector->data = (int*)malloc(sizeof(int) * pVector->capacity);

        if(pVector->data == NULL){

            free(pVector);
            return NULL;
        }

    }

    return pVector;

}

Boolean vector_is_empty(VECTOR hVector){

    Vector* pVector = (Vector*)hVector; //cast to the known type

    return (Boolean)(pVector->size <= 0);
    
}


void vector_destroy(VECTOR* phVector){

    Vector* pVector = (Vector*)*phVector; //cast to the known type
    free(pVector->data);
    free(pVector);
    *phVector = NULL;

}

Status vector_push_back(VECTOR hVector, int value)
{
    Vector* pVector = (Vector*)hVector;
    if(pVector->size >= pVector ->capacity)
    {
        int* temp = malloc(sizeof(int)*(pVector->capacity * 2)); //resize array to fit more values : O(n)
        if(temp == NULL)
        {
            return FAILURE;
        }

        for(int i=0; i<pVector->size; i++)
        {
            temp[i] = pVector->data[i];
        }
        free(pVector->data);
        pVector->data = temp;
        pVector->capacity *= 2;
        }
    pVector->data[pVector->size];
    return FAILURE;
}

Status vector_pop_back(VECTOR hVector)
{
    Vector* pVector = (Vector*)hVector;
    if(vector_is_empty(hVector))
    {
        return FAILURE;
    }
    return SUCCESS;
}

int* vector_at(VECTOR hVector, int index, Status pStatus)
{
    Vector* pVector = (Vector*)hVector;
    if(index < 0 || index >= pVector->size) //not in bounds
    {
        return NULL;
    }
    return pVector->data[index]; 
}

int vector_get_size(VECTOR hVector)
{
    Vector* pVector = (Vector*)hVector;
    return pVector->size;
}

int vector_get_capacity(VECTOR hVector)
{
    Vector* pVector = (Vector*)hVector;
    return pVector->capacity;
}