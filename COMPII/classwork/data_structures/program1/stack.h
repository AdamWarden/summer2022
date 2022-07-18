#ifndef STACK_H
#define STACK_H
#include "status.h"

typedef void* STACK;

STACK stack_init_default(void);

Status stack_push(STACK hStack, char* value);

Status stack_pop(STACK hStack);

Boolean stack_is_empty(STACK hStack);

char stack_top(STACK hStack, Status* pStatus); 

void stack_destroy(STACK* phStack);

Boolean read_string(void);

void clear_keyboard_buffer(void);

#endif
