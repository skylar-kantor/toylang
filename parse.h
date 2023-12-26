struct instruction
{
  char command[6];
  int arg;
} instruction;

struct instruction scan_file(FILE *in_file);