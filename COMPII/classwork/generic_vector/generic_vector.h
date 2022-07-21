#ifndef GENERIC_VECTOR_H
#define GENERIC_VECTOR_H
#include "status.h"
#include "generic.h"

typedef void* GENERIC_VECTOR;

GENERIC_VECTOR generic_vector_init_default(Status (*assignment)(ITEM* pLeft, ITEM pRight), void (*destroy)(ITEM* phInt));
Boolean generic_vector_is_empty(GENERIC_VECTOR hVector);
Status generic_vector_push_back(GENERIC_VECTOR hVector, ITEM pItem);
Status generic_vector_pop_back(GENERIC_VECTOR hVector);
int generic_vector_size(GENERIC_VECTOR hVector);
int generic_vector_capacity(GENERIC_VECTOR hVector);

ITEM* generic_vector_at(GENERIC_VECTOR hVector, int index);

generic_vector_destroy(GENERIC_VECTOR* phVector);
#endif