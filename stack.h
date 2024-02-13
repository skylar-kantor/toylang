#include <stdlib.h>
#include <stdio.h>

typedef struct stack_node
{
  int value;
  struct stack_node *next;
} stack_node;

typedef struct stack
{
  stack_node *head;
} stack;

stack *stack_init(void);
stack_node *stack_push(stack *stack, int val);
int stack_pop(stack *stack);
int stack_peek(stack *stack);
void stack_free(stack *stack);