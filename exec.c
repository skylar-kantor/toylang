#include "exec.h"
int add(stack *stack)
{
  stack_push(stack, stack_pop(stack) + stack_pop(stack));
  return stack_peek(stack);
}

int and (stack * stack)
{
  stack_push(stack, stack_pop(stack) & stack_pop(stack));
  return stack_peek(stack);
}

int or (stack * stack)
{
  stack_push(stack, stack_pop(stack) | stack_pop(stack));
  return stack_peek(stack);
}

int xor (stack * stack) {
  stack_push(stack, stack_pop(stack) ^ stack_pop(stack));
  return stack_peek(stack);
}

    int ls(stack *stack)
{
  stack_push(stack, stack_pop(stack) << stack_pop(stack));
  return stack_peek(stack);
}

int rs(stack *stack)
{
  stack_push(stack, stack_pop(stack) >> stack_pop(stack));
  return stack_peek(stack);
}

int nand(stack *stack)
{
  and(stack);
  stack_push(stack, ~stack_pop(stack));
  return stack_peek(stack);
}

int nor(stack *stack)
{
  or (stack);
  stack_push(stack, ~stack_pop(stack));
  return stack_peek(stack);
}

int dup(stack *stack)
{
  stack_push(stack, stack_peek(stack));
  return stack_peek(stack);
}

void stack_print(stack *stack)
{
  printf("%d\n", stack_peek(stack));
  return stack_peek(stack);
}

void jump(stack *stack, FILE *input_file)
{
  int current_instruction = 0;
  int jump_location = stack_pop(stack);
  fseek(input_file, SEEK_SET, SEEK_SET);
  while (current_instruction != jump_location)
  {
    fscanf(input_file, "%*[^\n]\n");
    current_instruction++;
  }
}

void ifeq(stack *stack, FILE *input_file)
{
  if (stack_pop(stack) == stack_pop(stack))
  {
    jump(stack, input_file);
  }
}

int execute_command(int command, int argument, stack *stack, FILE *input_file)
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
  return command;
}
