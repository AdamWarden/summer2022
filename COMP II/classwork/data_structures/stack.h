#ifndef STACK_H
#define STACK_H
#include "status.h"

typedef void* STACK;

STACK stack_init_Default(void);
void stack_destroy(STACK* phStack);
Status stack_push(STACK hStack, int value);
Status stack_pop(STACK hStack);
Boolean stack_is_empty(STACK hStack);
//Status stack_top(STACK hStack, int* pValue); way 1
int stack_top(STACK hStack, Status* pStatus); //way 2

#endif