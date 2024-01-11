#include "parse.h"
#include "exec.h"

int main(int argc, char *argv[])
{
  // Open the input and output files, so we have them ready
  if (argc < 2)
  {
    fprintf(stderr, "Usage: interp <in_file>\n");
    return 64;
  }
  FILE *input_file = fopen(argv[1], "r");
  if (input_file == NULL)
  {
    fprintf(stderr, "Couldn't open input file\n");
    return 2;
  }
  int scan_matches = 0;
  int instruction_pointer = 0;
  stack *stack = stack_init();
   while (1)
  {
    instruction *read_instruction = malloc(sizeof(instruction));
  //  printf("READ\n");
    scan_matches = scan_file(input_file, read_instruction);
   if(scan_matches == EOF)
   {
    break;
   }
   // printf("PARSE\n");
    int command = parse_command(read_instruction->command);
   // printf("EXEC\n");
    int argument = read_instruction->arg;
    //TODO make this argument a context struct?
    execute_command(command, argument, stack, input_file);
    instruction_pointer++;
  }

  // We're done with the input file, so close it ASAP
  fclose(input_file);

  // Read out the stack value at the end of the program
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