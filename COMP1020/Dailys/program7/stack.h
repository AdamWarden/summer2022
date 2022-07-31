#ifndef STACK_H
#define STACK_H
#include "status.h"

typedef void* STACK;

STACK stack_init_default(void);

Status stack_push(STACK hStack, char* value);

Status stack_pop(STACK hStack);

char stack_top(STACK hStack, Status* pStatus);

Boolean stack_is_empty(STACK hStack);

Boolean stack_balanced(char* expression); //returns true if the expression is balanced

void clear_keyboard_buffer(void);

void print_stack(STACK hStack);

void stack_destroy(STACK* phStack);

#endif