#include <stdio.h>
#include "parse.h"
#include "exec.h"

int main(int argc, char *argv[])
{
  //Open the input and output files, so we have them ready
  if (argc < 2)
    {
      fprintf(stderr, "Usage: interp <in_file>\n");
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
      fprintf(stderr, "Couldn't open input file\n");
      return 2;
    }
  //Go through all commands and execute them one by one
  do
    {
      instruction instr = scan_file(in_file);
      int cmd = parse_command(instr.command);
      int opcode[2] = {cmd, instr.arg};
      execute_command(opcode[0], opcode[1], stack);
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













