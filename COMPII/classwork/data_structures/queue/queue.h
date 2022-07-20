#ifndef QUEUE_H
#define QUEUE_H
#include "status.h"

typedef void* QUEUE;

QUEUE queue_init_default(void); //initialize opaque object

Boolean queue_is_empty(QUEUE hQ); //check if opaque object is empty

Status queue_insert(QUEUE hQ, int value); // insert value into back of array: fails if system runs out of memory

Status queue_service(QUEUE hQ); //remove value in array

int queue_front(QUEUE hQ, Status* pStatus);

void queue_destroy(QUEUE* phQ); //destroy opaque object

#endif