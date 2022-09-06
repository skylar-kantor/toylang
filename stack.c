#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

stack *stack_init()
{
  struct stack *stack = calloc(1, sizeof(stack));
  stack -> head = NULL;
  return stack;
}

stack_node *stack_push(stack *stack, int val)
{

  //create the new node
  struct stack_node *new_node = calloc(1, sizeof(stack_node));
  //set the previous top of the stack to be the next node of the new top
  new_node -> next = stack -> head;
  new_node -> value = val;
  //Add our new node to the top of the stack
  stack -> head = new_node;
  return new_node;
}

int stack_pop(stack *stack)
{
  if (stack -> head == NULL)
    {
      printf("Tried to pop from an empty stack\n");
      exit(1);
    }
  int val = stack -> head -> value;
  stack_node *old = stack->head;
  stack -> head = stack -> head -> next;
  free(old);
  return val;
}

int stack_peek(stack *stack)
{
  if (stack -> head == NULL)
    {
      printf("Tried to read an empty stack\n");
      exit(1);
    }
  return stack->head->value;
}

void stack_free (stack *stack)
{
  if (stack == NULL)
    {
      return;
    }
 
  stack_node *to_free = stack->head;
  do
    {
      if (to_free == NULL)
	return;
      stack_node *next_free = to_free->next;
      
      free(to_free);
      to_free = next_free;
    }while (to_free != NULL);
  free(stack);
}
      
  
