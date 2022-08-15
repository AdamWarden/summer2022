#include <stdio.h>
#include <stdlib.h>
#include "BIT_FLAGS_1.h"
#include "status.h"

struct bit_flags
{
    int size;
    int capacity;
    int* data;
};
typedef struct bit_flags Bit_flags;

const int size_of_int = sizeof(unsigned int)*8; //size of int in bits

BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits) //initialize bit flags object with given number of bits
{
    int index = 0; //number of ints needed to store the bits
    int i = 0;
    Bit_flags* pBit_flags;
    if (number_of_bits > 0)// if the given number is positive
        {
            pBit_flags = (Bit_flags*)malloc(sizeof(Bit_flags));//allocate memoery
            if(pBit_flags == NULL)
            {
                printf("Failed to allocate memory for bit flags object\n");
                return NULL;
            }
            else if (pBit_flags != NULL)
                {
                    if(number_of_bits % size_of_int) //if number of bits is not a multiple of size of int
                    {
                        index = (number_of_bits / size_of_int) + 1; //increase index to allow for extra int
                    }
                    else
                    {
                        index = number_of_bits / size_of_int; 
                    }
                    pBit_flags->capacity = index*size_of_int; //set capacity to number of ints needed
                    pBit_flags->size = number_of_bits; //set size to number of bits
                    pBit_flags->data = (int*)malloc(index * sizeof(int));
                    if (pBit_flags->data == NULL)
                    {
                        printf("Failed to allocate memory\n");
                        free(pBit_flags);
                        pBit_flags = NULL;
                        return NULL;
                    }
                    else
                    {
                        for(i=0; i<index; i++)
                        {
                            pBit_flags->data[i] = 0; //set all ints to 0
                        }
                    }
                }
        }
    else //if given an invalid number
    {
        printf("Entered value must be greater than 0\n");
        pBit_flags = NULL;
    }
    return (BIT_FLAGS)pBit_flags;
}

Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position) //set flag at given position
{
    int* pTemp;
    int i;
    int index = 0;
    Bit_flags* pBit_flags = (Bit_flags*)hBit_flags; //cast to the known type
    if ((flag_position) >= pBit_flags->capacity) //if the position is out of bounds
    {
        //pTemp = (int*)malloc(sizeof(int) * (pBit_flags->capacity + size_of_int)); //allocates more memory than needed
        pTemp = realloc(hBit_flags, flag_position - pBit_flags->capacity); 
        //reallocate the memory to fit by increasing the capacity by the difference betweenthe position and capacity
        if (pTemp == NULL)
        {
            printf("Failed to allocate more memory\n");
            return FAILURE;
        }
        else
        {
            for (i=0; i<pBit_flags->size; i++) //copy old data to new memory
            {
                pTemp[i] = pBit_flags->data[i];
            }
            free(pBit_flags->data); //free old memory
            pBit_flags->data = pTemp; //set new memory to old memory
            pBit_flags->capacity = flag_position + 1; //set new capacity to new position
        }
    }
    index = flag_position / size_of_int; //find index of int to set flag in
    if (flag_position >= pBit_flags->size) //if the position is out of bounds
	{
		pBit_flags->size = flag_position + 1; //set size to position + 1
	}
    pBit_flags->data[index] |= (1 << flag_position); //set flag
    return SUCCESS;
}

Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position) //unset flaf at given position
{
    int* pTemp;
    int i;
    int index = 0;
    Bit_flags* pBit_flags = (Bit_flags*)hBit_flags; //cast to the known type
    if (flag_position >= pBit_flags->capacity) //if the position is out of bounds
    {
        //pTemp = (int*)malloc(sizeof(int) * (pBit_flags->capacity + size_of_int)); //allocates more memory
        pTemp = realloc(hBit_flags, flag_position - pBit_flags->capacity); //reallocate the memory to fit by increasing the capacity by the difference betweenthe position and capacity
        if (pTemp == NULL)
        {
            printf("Could not resize bit flags object");
            return FAILURE;
        }
        else
        {
            for (i=0; i<pBit_flags->size; i++) //copy old data to new memory
            {
                pTemp[i] = pBit_flags->data[i];
            }
            free(pBit_flags->data);
            pBit_flags->data = pTemp;
            //pBit_flags->capacity += size_of_int;
            pBit_flags->capacity = flag_position + 1;
        }
    }
    index = flag_position / size_of_int;
    if (flag_position >= pBit_flags->size)
	{
		pBit_flags->size = flag_position + 1;
	}
    pBit_flags->data[index] &= ~(1 << flag_position); //unset flag
    return SUCCESS;
}

int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position)
{
    /*
    int bit, index = 0; //bit to check & index of int to check in
    index = flag_position / size_of_int; //find index of int to check in

     Bit_flags* pBit_flags = (Bit_flags*)hBit_flags; //cast to the known type

     if (flag_position < 0 || flag_position > pBit_flags->capacity) //if the position is out of bounds
     {
         bit = -1; //return invalid bit
     }
     else
     {
         bit = (pBit_flags->data[index] >> flag_position) & 1; //check bit
     }

    return bit;
    */
    Bit_flags* pBit_flags = (Bit_flags*)hBit_flags; //cast to the known type
    int bit = 0;
    int i, j;
    int size_of_int = sizeof(int)*8;

    if(pBit_flags == NULL)
    {
        printf("Bit flags object is NULL\n");
        return -1;
    }
    else if(flag_position < 0 || flag_position > pBit_flags->capacity)
    {
        printf("Flag position is out of bounds\n");
        return -1;
    }
    else
    {
        i = flag_position / size_of_int; //find index of int to check in
        j = flag_position % size_of_int; //find bit to check in int
        return (pBit_flags->data[i] & (1 << j)) != 0; //returns 1 if bit is set, 0 if bit is not set
    }
}

int bit_flags_get_size(BIT_FLAGS hBit_flags)
{
    Bit_flags* pBit_flags = (Bit_flags*)hBit_flags; //cast the void* object to a Bit_flag* object
    return pBit_flags->size;
}

int bit_flags_get_capacity(BIT_FLAGS hBit_flags)
{
    Bit_flags* pBit_flags = (Bit_flags*)hBit_flags; //cast the void* object to a Bit_flag* object
    return pBit_flags->capacity;
}


void bit_flags_destroy(BIT_FLAGS* phBit_flags)
{
    Bit_flags* pBit_flags = (Bit_flags*)phBit_flags; //cast the void* object to a Bit_flag* object
    free(pBit_flags->data);
    free(pBit_flags);//clean up the memory footprint of the object
    *phBit_flags = NULL;
    return;
}
