#include "status.h"
typedef void* VECTOR;

VECTOR vector_init_default(void); //initialize opaque object

Boolean vector_is_empty(VECTOR hVector); //check if opaque object is empty

Status vector_push_back(VECTOR hVector, int value); // insert value into back of array: fails if system runs out of memory

Status vector_pop_back(VECTOR hVector); //remove value in array

int* vector_at(VECTOR hVector, int index, Status pStatus); //gets address at certain index

int vector_get_size(VECTOR hVector); //return size of array

int vector_get_capacity(VECTOR hVector); //return capacity of array

void vector_destroy(VECTOR* phVector); //destroy opaque object