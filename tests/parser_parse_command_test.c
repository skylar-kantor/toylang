#include "../parse.h"
#include <stdlib.h>

int main(void)
{
    char *test_valid_commands[14] = {"push", "pop", "add", "ifeq", "jump", "print", "dup", "and", "nand", "or", "nor", "xor", "ls", "rs"};
    printf("Testing valid_commands\n");
    for (int i = 0; i < 14; i++)
    {
        int opcode = parse_command(test_valid_commands[i]);
        if (opcode != i)
        {
            printf("Failed parse_cmd test: Valid command. Exptected %s to return command #%d, but returned %d\n", test_valid_commands[i], i, opcode);
            return 0;
        }
    }
    printf("Passed valid_commands\n");

    printf("Testing invalid_commands\n");
    char *test_invalid_commands[5] = {"", "9", "pushh", "o", "\n"};
    for (int i = 0; i < 5; i++)
    {
        int opcode = parse_command(test_invalid_commands[i]);
        if (opcode != -1)
        {
            printf("Failed parse_cmd test: Valid command. Exptected %s to return command # -1, but returned %d\n", test_invalid_commands[i], opcode);
            return 0;
        }
    }
    printf("Passed invalid_commands\n");
    return 0;
}