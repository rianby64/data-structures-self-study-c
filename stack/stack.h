
#ifndef STACK_STACK_H
#define STACK_STACK_H

#include <stdbool.h>

#include "../llist/llist.h"

typedef struct stack {
  Llist *list;
} Stack;

Stack* Stack_new();
void Stack_free(Stack *s);

#include "stack.c"

#endif