#include "stack.h"
#include <stdio.h>

int add(stack *stack);
int and (stack * stack);
int or (stack * stack);
int xor (stack * stack);
int ls(stack *stack);
int rs(stack *stack);
int nand(stack *stack);
int nor(stack *stack);
void dup(stack *stack);
void stack_print(stack *stack);
void execute_command(int command, int argument, stack *stack, FILE *input_file);