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
  printf("%d\n", stack_peek(stack));
}

void jump(stack *stack, FILE *input_file) {
  int jump_location = stack_pop(stack) * 4;
  fseek(input_file, jump_location, SEEK_SET);
}

void ifeq(stack *stack, FILE *input_file) {
  
  if (stack_pop(stack) == stack_pop(stack)) {
    jump(stack, input_file);
  }
}

void execute_command(int command, int argument, stack *stack, FILE *input_file)
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
    ifeq(stack, input_file);
    break;
  case 4:
    jump(stack, input_file);
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
