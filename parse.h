typedef struct instruction
{
  char command[6];
  int arg;
} instruction;

instruction scan_file(FILE *in_file);