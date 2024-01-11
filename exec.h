#include "stack.h"
#include <stdio.h>

void add(stack *stack);
void and (stack *stack);
void or (stack *stack);
void xor (stack *stack);
void ls(stack *stack);
void rs(stack *stack);
void nand(stack *stack);
void nor(stack *stack);
void dup(stack *stack);
void stack_print(stack *stack);
void execute_command(int command, int argument, stack *stack, FILE *input_file);