#include "stack.h"
#include <stdio.h>

int add(Stack *stack);
int and (Stack * stack);
int or (Stack * stack);
int xor (Stack * stack);
int ls(Stack *stack);
int rs(Stack *stack);
int nand(Stack *stack);
int nor(Stack *stack);
void dup(Stack *stack);
void stack_print(Stack *stack);
void execute_command(int command, int argument, Stack *stack, FILE *input_file);
