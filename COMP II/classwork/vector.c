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


void vector_destroy(VECTOR hVector){

    Vector* pVector = (Vector*)hVector; //cast to the known type
    free(pVector->data);
    free(pVector);

}