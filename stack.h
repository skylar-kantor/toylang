#include <stdlib.h>
#include <stdio.h>

typedef struct stack_node
{
  int value;
  struct stack_node *next;
} stack_node;

typedef struct Stack
{
  stack_node *head;
} Stack;

Stack *stack_init(void);
stack_node *stack_push(Stack *stack, int val);
int stack_pop(Stack *stack);
int stack_peek(Stack *stack);
void stack_free(Stack *stack);
