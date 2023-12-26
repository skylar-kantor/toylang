#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
#include "exec.h"

void add(stack *stack)
{
  stack_push(stack, stack_pop(stack) + stack_pop(stack));
}

void and(stack *stack)
{
  stack_push(stack, stack_pop(stack) & stack_pop(stack));
}

void or(stack *stack)
{
  stack_push(stack, stack_pop(stack) | stack_pop(stack));
}

void xor(stack *stack)
{
  stack_push(stack, stack_pop(stack) ^ stack_pop(stack));
}

void ls(stack *stack)
{
  stack_push(stack, stack_pop(stack) << stack_pop(stack));
}

void rs(stack *stack)
{
  stack_push(stack, stack_pop(stack) >> stack_pop(stack));
}

void nand(stack *stack)
{
  and(stack);
  stack_push(stack, ~stack_pop(stack));
}

void nor(stack *stack)
{
  or(stack);
  stack_push(stack, ~stack_pop(stack));
}

void dup(stack *stack)
{
  stack_push(stack, stack_peek(stack));
}

void stack_print(stack *stack)
{
  print(stack_peek(stack));
}







