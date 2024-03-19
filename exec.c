#include "exec.h"
int add(Stack *stack)
{
  stack_push(stack, stack_pop(stack) + stack_pop(stack));
  return stack_peek(stack);
}

int and (Stack * stack)
{
  stack_push(stack, stack_pop(stack) & stack_pop(stack));
  return stack_peek(stack);
}

int or (Stack * stack)
{
  stack_push(stack, stack_pop(stack) | stack_pop(stack));
  return stack_peek(stack);
}

int xor (Stack * stack) {
  stack_push(stack, stack_pop(stack) ^ stack_pop(stack));
  return stack_peek(stack);
}

    int ls(Stack *stack)
{
  stack_push(stack, stack_pop(stack) << stack_pop(stack));
  return stack_peek(stack);
}

int rs(Stack *stack)
{
  stack_push(stack, stack_pop(stack) >> stack_pop(stack));
  return stack_peek(stack);
}

int nand(Stack *stack)
{
  and(stack);
  stack_push(stack, ~stack_pop(stack));
  return stack_peek(stack);
}

int nor(Stack *stack)
{
  or (stack);
  stack_push(stack, ~stack_pop(stack));
  return stack_peek(stack);
}

void dup(Stack *stack)
{
  stack_push(stack, stack_peek(stack));
}

void stack_print(Stack *stack)
{
  printf("%d\n", stack_peek(stack));
}

void jump(Stack *stack, FILE *input_file)
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

void new_func(char *name, char *def)
{
  
}

void call_func(char **args)
{
  
}

void ifeq(Stack *stack, FILE *input_file)
{
  if (stack_pop(stack) == stack_pop(stack))
  {
    jump(stack, input_file);
  }
}

void do_if(Stack *stack)
{
 int operand = stack_pop(stack);
 int v1 = stack_pop(stack);
 int v2 = stack_pop(stack);

 switch (operand)
 {
 case 0:
  if(v1 == v2)
  {
    stack_push(stack, 1);
  }
  else
  {
    stack_push(stack,0);
  }
  break;

  case 1:
  if(v1 < v2)
  {
    stack_push(stack, 1);
  }
  else
  {
    stack_push(stack,0);
  }
  break;

   case 2:
  if(v1 > v2)
  {
    stack_push(stack, 1);
  }
  else
  {
    stack_push(stack,0);
  }
  break;

   case 3:
  if(v1 <= v2)
  {
    stack_push(stack, 1);
  }
  else
  {
    stack_push(stack,0);
  }
  break;

   case 4:
  if(v1 >= v2)
  {
    stack_push(stack, 1);
  }
  else
  {
    stack_push(stack,0);
  }
  break;
 
 default:
  break;
 }
}

void execute_command(int command, int argument, Stack *stack, FILE *input_file)
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
  case 14:
    do_if(stack);
    break;
  case 15: 
    new_func("", "");
    break;
  default:
    break;
  }
}
