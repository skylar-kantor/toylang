//The command and argument
struct instruction
{
  char command[6];
  int arg;
} instruction;

//Scan the line, and get the command and argument
struct instruction scanfile(FILE *in_file)
{
  struct instruction instr;
  char cmd[7];
  int arg;
  scan = fscanf(in_file, "%6s %d", cmd, &arg);
  if (scan == 1)
    {
      arg = -1;
    }
  if (scan < 1)
    {
      break;
    }

  instr.arg = arg;
  strcpy(instr.cmd, cmd);
  return instr;
} 



int[2] parse(struct instruction instr)
{
  //determine the command
  if (strcmp(instr.cmd, "push") == 0)
    {
      return {0,instr.arg};
    }
  else if (strcmp(instr.cmd, "pop") == 0)
    {
       return {1,instr.arg};
    }
  else if (strcmp(instr.cmd, "add") == 0)
    {
       return {2,instr.arg};
    }
  else if (strcmp(instr.cmd, "ifeq") == 0)
    {
       return {3,instr.arg};
    }
  else if (strcmp(instr.cmd, "jump") == 0)
    {
      return {4,instr.arg};
    }
  else if (strcmp(instr.cmd, "print") == 0)
    {
       return {5,instr.arg};
    }
  else if (strcmp(instr.cmd, "dup") == 0)
    {
       return {6,instr.arg};
    }
  else if (strcmp(instr.cmd, "and") == 0)
    {
      return {7,instr.arg};
    }
  else if (strcmp(instr.cmd, "nand") == 0)
    {
       return {8,instr.arg};
    }
  else if (strcmp(instr.cmd, "or") == 0)
    {
      return({9,instr.arg};
    }
  else if (strcmp(instr.cmd, "nor") == 0)
    {
      return {10, instr.arg};
    }
  else if (strcmp(instr.cmd, "xor") == 0)
    {
       return {11,instr.arg};
    }
  else if (strcmp(instr.cmd, "ls") == 0)
    {
       return {12,instr.arg};
    }
  else if (strcmp(instr.cmd, "rs") == 0)
    {
      return {13,instr.arg};
    }
  else
    {
      fprintf(stderr, "ERROR: \"%s\", ", instr.cmd);
      return {-1, -1}
    }
}

