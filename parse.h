#include <stdio.h>
#include <string.h>
typedef struct instruction
{
  char command[6];
  int arg;
} instruction;

instruction scan_file(FILE *in_file);
int parse_command(char *cmd);