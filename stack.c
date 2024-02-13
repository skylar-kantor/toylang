#include "stack.h"

stack *stack_init(void)
{
  stack *stack = calloc(1, sizeof(stack));
 
  return stack;
}

stack *stack_increase(stack *stack) {
  stack_node *nodes[(stack->capacity) * 2];
 
  struct stack *new_stack = calloc(1, sizeof(stack));
  new_stack->capacity = stack->capacity * 2;
   for (int i  = 0; i < stack->capacity; i++)
  {
    new_stack->head[i] = stack->head[i];
  }
  new_stack->top = 0;
  return new_stack;
}

stack_node *stack_push(stack *stack, int val)
{
  if (stack == NULL)
  {
    fprintf(stderr, "Tried to push to stack that doesn't exist\n");
    return NULL;
  }

  stack_node *new_node = calloc(1, sizeof(stack_node));
  
  new_node->value = val;
  if (stack->top + 1 < stack->capacity)
  {
  (stack->head)[stack->top] = new_node;
  stack->top = 1 + stack->top;
  return new_node;
  }
  else
  {
    stack = stack_increase(stack);
    return stack_push(stack, val);
  }
  
}

int stack_pop(stack *stack)
{
  if (stack == NULL)
  {
    fprintf(stderr, "Tried to pop from stack that doesn't exist\n");
    return 1;
  }
  if (stack->head == NULL)
  {
    fprintf(stderr, "Tried to pop from an empty stack\n");
    exit(1);
  }
  int val = ((stack->head)[stack->top])->value;
  stack->top = (stack->top) - 1;
  return val;
}

int stack_peek(stack *stack)
{
  if (stack == NULL)
  {
    fprintf(stderr, "Tried to read from stack that doesn't exist\n");
    return 1;
  }
  if (stack->head == NULL)
  {
    fprintf(stderr, "Tried to read an empty stack\n");
    exit(1);
  }
  return stack->head[stack->top]->value;
}

void stack_free(stack *stack)
{
  if (stack == NULL)
  {
    return;
  }

 free(stack->head);
 free(stack);
 return 0;
}
