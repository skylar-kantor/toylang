#include <stdio.h>
#include <string.h>
typedef struct instruction
{
  char command[6];
  int arg;
} instruction;

int scan_file(FILE *in_file,  instruction *out_instr);
int parse_command(char *cmd);