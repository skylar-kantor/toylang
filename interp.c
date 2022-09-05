#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char *argv[])
{
  //Open the input and output files, so we have them ready
  if (argc < 2)
    {
      printf("Usage: interp <in_file>\n");
      return 64;
    }
  FILE *in_file = fopen(argv[1], "r");
  char cmd[6];
  int arg;
  int scan;
  int ins_ptr = 0;
  stack *stack = stack_init();
  if (in_file == NULL)
    {
      printf("Couldn't open input file\n");
      return 2;
    }
  //Go through all commands and execute them one by one
  do
    {
      //Scan the line, and get the command and argument
      scan = fscanf(in_file, "%s %d", cmd, &arg);
      if (scan == 1)
	{
	  arg = -1;
	}
      if (scan < 1)
	{
	  break;
	}

      //determine the command
      if (strcmp(cmd, "push") == 0)
	{
	  stack_push(stack, arg);
	}
      else if (strcmp(cmd, "pop") == 0)
	{
	  stack_pop(stack);
	}
      else if (strcmp(cmd, "add") == 0)
	{
	  if (stack -> head != NULL && stack->head->next != NULL)
	    {
	    int a = stack_pop(stack);
	    int b = stack_pop(stack);
	    stack_push(stack, a+b);
	    }
	  else
	    {
	      printf("Tried to add with fewer than two nodes in a stack");
	      exit(1);
	    }
	}
      else if (strcmp(cmd, "ifeq") == 0)
	{
	  if (stack_peek(stack) == 0)
	    {
	      while (ins_ptr < arg-1)
		{
		  char c;
		  do {
		    c = fgetc(in_file);
		  } while (c != '\n');
		  ins_ptr++;
		  
		}
	    }
	}
     else if (strcmp(cmd, "jump") == 0)
	{
	  while (ins_ptr < arg-1)
	    {
	      char c;
	      do {
		c = fgetc(in_file);
	      } while (c != '\n');
	      ins_ptr++;
		  
	    }
	}
     else if (strcmp(cmd, "print") == 0)
	{
	  printf("%d\n", stack_peek(stack));
	}
     else if (strcmp(cmd, "dup") == 0)
	{
	  stack_push(stack, stack_peek(stack));
	}
     else if (strcmp(cmd, "and") == 0)
       {
	 int val1 = stack_pop(stack);
	 int val2 = stack_pop(stack);
	 stack_push(stack, val1 & val2);
       }
       else if (strcmp(cmd, "nand") == 0)
       {
	 int val1 = stack_pop(stack);
	 int val2 = stack_pop(stack);
	 stack_push(stack, ~(val1 & val2));
       }
     else if (strcmp(cmd, "or") == 0)
       {
	 int val1 = stack_pop(stack);
	 int val2 = stack_pop(stack);
	 stack_push(stack, val1 | val2);
       }
     else if (strcmp(cmd, "nor") == 0)
       {
	 int val1 = stack_pop(stack);
	 int val2 = stack_pop(stack);
	 stack_push(stack, ~(val1 | val2));
       }
       else if (strcmp(cmd, "xor") == 0)
       {
	 int val1 = stack_pop(stack);
	 int val2 = stack_pop(stack);
	 stack_push(stack, val1 ^ val2);
       }
       else if (strcmp(cmd, "ls") == 0)
       {
	 int value = stack_pop(stack);
	 int shift = stack_pop(stack);
	 stack_push(stack, value >> shift);
       }
       else if (strcmp(cmd, "rs") == 0)
       {
	 int value = stack_pop(stack);
	 int shift = stack_pop(stack);
	 stack_push(stack, value >> shift);
       }
     else
       {
	 printf("Unrecognized command \"%s\"\n", cmd);
	 return 1;
       }
      ins_ptr++;
    } while (scan != EOF);

  //We're done with the input file, so close it ASAP
  fclose(in_file);

  //Read out the stack value at the end of the program
  printf("=========FINAL STACK VALUE==============\n");
  stack_node *head = stack->head;
  while (head != NULL)
    {
      printf("%d, ", head->value);
      stack_pop(stack);
      head = stack->head;
    }
  printf("\n");
  stack_free(stack);
  return 0;
  
}













