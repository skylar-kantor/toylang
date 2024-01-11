#include "parse.h"

int scan_file(FILE *in_file, instruction *out_instr)
{
  instruction read_instruction;
  char cmd[7];
  int arg;
  int scan_matches = fscanf(in_file, "%6s %d", cmd, &arg);
  if (scan_matches == 1)
  {
    read_instruction.arg = -1;
  }
  if (scan_matches < 1)
  {
    instruction error_instruction = {.command = -1, .arg = -1};
    *out_instr = error_instruction;
    // return 0;
  }
  // printf("FOUND %d MATCHES\n", scan_matches);

  read_instruction.arg = arg;
  strcpy(read_instruction.command, cmd);
  // printf("COPYING\n");
  *out_instr = read_instruction;
  return scan_matches;
}

int parse_command(char *cmd)
{
  // determine the command
  if (strcmp(cmd, "psh") == 0)
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
  else if (strcmp(cmd, "ifq") == 0)
  {
    return 3;
  }
  else if (strcmp(cmd, "jmp") == 0)
  {
    return 4;
  }
  else if (strcmp(cmd, "prt") == 0)
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
  else if (strcmp(cmd, "nnd") == 0)
  {
    return 8;
  }
  else if (strcmp(cmd, "_or") == 0)
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
  else if (strcmp(cmd, "lfs") == 0)
  {
    return 12;
  }
  else if (strcmp(cmd, "rts") == 0)
  {
    return 13;
  }
  else
  {
    fprintf(stderr, "ERROR: \"%s\", ", cmd);
    return -1;
  }
}
