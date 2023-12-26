#include "parse.h"

instruction scan_file(FILE *in_file)
{
  instruction instr;
  char cmd[7];
  int arg;
  int scan = fscanf(in_file, "%6s %d", cmd, &arg);
  if (scan == 1)
    {
      arg = -1;
    }
  if (scan < 1)
    {
      return instr;
    }

  arg = instr.arg;
  strcpy(instr.command, cmd);
  return instr;
} 



int parse_command(char *cmd)
{
  //determine the command
  if (strcmp(cmd, "push") == 0)
    {
      return 0;
    }
  else if (strcmp(cmd, "pop") == 0)
    {
       return 1;
    }
  else if (strcmp(cmd, "add") == 0)
    {
       return 2;
    }
  else if (strcmp(cmd, "ifeq") == 0)
    {
       return 3;
    }
  else if (strcmp(cmd, "jump") == 0)
    {
      return 4;
    }
  else if (strcmp(cmd, "print") == 0)
    {
       return 5;
    }
  else if (strcmp(cmd, "dup") == 0)
    {
       return 6;
    }
  else if (strcmp(cmd, "and") == 0)
    {
      return 7;
    }
  else if (strcmp(cmd, "nand") == 0)
    {
       return 8;
    }
  else if (strcmp(cmd, "or") == 0)
    {
     return 9;
    }
  else if (strcmp(cmd, "nor") == 0)
    {
      return 10;
    }
  else if (strcmp(cmd, "xor") == 0)
    {
       return 11;
    }
  else if (strcmp(cmd, "ls") == 0)
    {
       return 12;
    }
  else if (strcmp(cmd, "rs") == 0)
    {
      return 13;
    }
  else
    {
      fprintf(stderr, "ERROR: \"%s\", ", cmd);
      return -1;
    }
}

