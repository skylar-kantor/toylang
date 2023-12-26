#include "exec.h"
void add(stack *stack)
{
  stack_push(stack, stack_pop(stack) + stack_pop(stack));
}

void and (stack * stack)
{
  stack_push(stack, stack_pop(stack) & stack_pop(stack));
}

void or (stack * stack)
{
  stack_push(stack, stack_pop(stack) | stack_pop(stack));
}

void xor (stack * stack) {
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
  or (stack);
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

void execute_command(int command, int argument, stack *stack)
{

  switch (command)
  {
  case 0:
    stack_push(stack, argument);
    break;
  case 1:
    stack_pop(stack);
    break;
  case 2:
    add(stack);
    break;
  case 3:
    // ifeq(stack, argument);
    break;
  case 4:
    // jump(argument);
    break;
  case 5:
    stack_print(stack);
    break;
  case 6:
    dup(stack);
    break;
  case 7:
    and(stack);
    break;
  case 8:
    nand(stack);
    break;
  case 9:
    or (stack);
    break;
  case 10:
    nor(stack);
    break;
  case 11:
    xor(stack);
    break;
  case 12:
    ls(stack);
    break;
  case 13:
    rs(stack);
    break;
  default:
    break;
  }
}
