#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main(int argc, char* argv[])
{
    VECTOR hVector;

    //initialization of object
    vector_init_default(); //creates known type structure (object) and returns address of where the object is located
    hVector = vector_init_default();

    if(hVector == NULL){
        printf("Failed to allocate space for vector object.\n");
        exit(1);
    }

    for(int i=0; ;i++)
    {
        if(vector_push_back(hVector, 42) == FAILURE)
        {
            printf("Failed to allocate memory\n");
            exit(1);
        }
    }
    
    //destruction of object
    vector_destroy(hVector);

    return 0;
}