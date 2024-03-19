#include "../parse.h"
#include <stdlib.h>

int main(void)
{
    printf("==================\n==================\nTesting scan_file()\n==================\n==================\n");
    // Test that a single, valid instruction in a file returns a correct result

    // Commands without argument should return 1, set the argument of instruction to -1, and store the text before the single space in instruction->command
    printf("Testing single_good_noarg\n");
    FILE *single_good_noarg = fopen("scanfile_single_good_cmd_noarg", "r");
    instruction *result = calloc(1, sizeof(instruction));
    int matches = scan_file(single_good_noarg, result);
    if (matches != 1)
    {
        printf("scan_file() test: Failed single command with no argument.\nscan_file returned %d, should have returned 1\n", matches);
        free(result);
        return 0;
    }
    if (result->arg != -1)
    {
        printf("scan_file() test: Failed single command with no argument.\nArgument is %d, but should be -1\n", result->arg);
        free(result);
        return 0;
    }
    if (strcmp(result->command, "add") != 0)
    {
        printf("scan_file() test: Failed single command with no argument.\nCommand is %s, but file contains \"add\"\n", result->command);
        free(result);
        return 0;
    }
    free(result);
    printf("Passed single_good_noarg\n");

    // Commands with argument should return a number > 1, set instruction->argument to the integer after the single space, and the command should be set to the text in the file before the whitespace
    // This only happens with push
    printf("Testing single_good_arg\n");
    FILE *single_good_arg = fopen("scanfile_single_good_cmd_arg", "r");
    result = malloc(sizeof(instruction));
    matches = scan_file(single_good_arg, result);
    if (matches != 2)
    {
        printf("scan_file() test: Failed single command with argument.\nscan_file returned %d, should have returned 1\n", matches);
        free(result);
        return 0;
    }
    if (result->arg != 3)
    {
        printf("scan_file() test: Failed single command with argument.\nArgument is %d, but should be 3\n", result->arg);
        free(result);
        return 0;
    }
    if (strcmp(result->command, "push") != 0)
    {
        printf("scan_file() test: Failed single command with argument.\nCommand is %s, but file contains \"push\"\n", result->command);
        free(result);
        return 0;
    }
    free(result);
    printf("Passed single_good_arg\n");

    // Empty file should return -1
    printf("Testing empty_file\n");
    FILE *empty = fopen("scanfile_empty_file", "r");
    result = malloc(sizeof(instruction));
    matches = scan_file(empty, result);
    if (matches != -1)
    {
        printf("scan_file() test: Failed empty file.\nscan_file returned %d, should have returned -1\n", matches);
        free(result);
        return 0;
    }
    if (result->arg != -1)
    {
        printf("scan_file() test: Failed empty file.\nArgument is %d, but should be -1\n", result->arg);
        free(result);
        return 0;
    }
    free(result);

    // Test that multiple, valid instructions in a file returns a correct result
    printf("Testing multi_good_noarg\n");
    FILE *multiple_good_cmd_noarg = fopen("scanfile_multi_good_cmd_noarg", "r");
    int count = 1;
    const int FILE_LEN = 10;
    while (1)
    {
        instruction *result = malloc(sizeof(instruction));
        int matches = scan_file(multiple_good_cmd_noarg, result);
        if (matches == -1)
        {
            if (count <= FILE_LEN)
            {
                printf("scan_file() test: Failed multi command with no argument on loop %d. scan_file returned EOF before line %d\n", count, FILE_LEN);
                free(result);
                return 0;
            }
            else
            {
                break;
            }
        }

        if (matches != 1 && matches != -1)
        {
            printf("scan_file() test: Failed multi command with no argument on loop %d.\nscan_file returned %d, should have returned 1\n", count, matches);
            free(result);
            return 0;
        }
        if (result->arg != -1)
        {
            printf("scan_file() test: Failed multi command with no argument on loop %d.\nArgument is %d, but should be -1\n", count, result->arg);
            free(result);
            return 0;
        }
        if (strcmp(result->command, "add") != 0 && strcmp(result->command, "print") != 0)
        {
            printf("scan_file() test: Failed multi command with no argument on loop %d.\nCommand is %s, but file contains \"add\"\n", count, result->command);
            free(result);
            return 0;
        }

        count++;
    }
    free(result);
    printf("Passed multi_good_noarg\n");

    // Test that a single instruction, that is in the correct form, but not a valid instruction still returns a command
    printf("Testing correct_form_no_cmd_noarg\n");
    FILE *correct_form_no_cmd = fopen("scanfile_correct_form_no_cmd", "r");
    result = calloc(1, sizeof(instruction));
    matches = scan_file(correct_form_no_cmd, result);
    if (matches != 1)
    {
        printf("scan_file() test: Failed no command, correct format with no arguments.\nscan_file returned %d, should have returned 1\n", matches);
        free(result);
        return 0;
    }
    if (result->arg != -1)
    {
        printf("scan_file() test: Failed no command, correct format with no arguments.\nArgument is %d, but should be -1\n", result->arg);
        free(result);
        return 0;
    }
    free(result);
    printf("Passed correct_form_no_cmd_noarg\n");

    // Test that a single instruction in an incorrect format returns an error

    // Command too long (more than 6 chars)
    // This should truncate the command, but otherwise act as though nothing is wrong
    printf("Testing cmd_too_long\n");
    FILE *cmd_too_long = fopen("scanfile_cmd_too_long", "r");
    result = calloc(1, sizeof(instruction));
    matches = scan_file(cmd_too_long, result);
    if (matches != 1)
    {
        printf("scan_file() test: Failed command too long.\nscan_file returned %d, should have returned 1\n", matches);
        printf("%s, %d\n", result->command, result->arg);
        free(result);
        return 0;
    }
    if (result->arg != -1)
    {
        printf("scan_file() test: Failed command too long.\nArgument is %d, but should be -1\n", result->arg);
        free(result);
        return 0;
    }
    if (strcmp(result->command, "aaaaad") != 0)
    {
        printf("scan_file() test: Failed command too long. Command should have truncated to \"aaaaad\", instead is %s\n", result->command);
        free(result);
        return 0;
    }
    free(result);
    printf("Passed cmd_too_long\n");

    // Command too short (Essentially, no command)
    printf("Testing cmd_too_short\n");
    FILE *cmd_too_short = fopen("scanfile_too_short", "r");
    result = calloc(1, sizeof(instruction));
    matches = scan_file(cmd_too_short, result);
    if (matches != 1)
    {
        printf("scan_file() test: Failed command too short.\nscan_file returned %d, should have returned 1\n", matches);
        free(result);
        return 0;
    }
    if (result->arg != -1)
    {
        printf("scan_file() test: Failed command too short.\nArgument is %d, but should be -1\n", result->arg);
        free(result);
        return 0;
    }
    free(result);
    printf("Passed cmd_too_short\n");

    // Too much whitespace
    // Since fscanf ignores multiple whitespace characters, this shouldn't be different from a correctly formatted command
    printf("Testing too_much_whitespace\n");
    FILE *too_much_space = fopen("scanfile_too_much_whitespace", "r");
    result = calloc(1, sizeof(instruction));
    matches = scan_file(too_much_space, result);
    if (matches != 2)
    {
        printf("scan_file() test: Failed too much whitespace.\nscan_file returned %d, should have returned 2\n", matches);
        free(result);
        return 0;
    }
    if (result->arg != 5)
    {
        printf("scan_file() test: Failed too much whitespace.\nArgument is %d, but should be 5\n", result->arg);
        free(result);
        return 0;
    }
    free(result);
    printf("Passed too_much_whitespace\n");

    // Too little whitespace
    printf("Testing too_little_whitespace\n");
    FILE *too_little_space = fopen("scanfile_too_little_whitespace", "r");
    result = calloc(1, sizeof(instruction));
    matches = scan_file(too_little_space, result);
    if (matches < 1)
    {
        printf("scan_file() test: Failed too little whitespace.\nscan_file returned %d, should have returned at least 1\n", matches);
        printf("%s, %d\n", result->command, result->arg);
        free(result);
        return 0;
    }
    if (result->arg != -1)
    {
        printf("scan_file() test: Failed too little whitespace.\nArgument is %d, but should be -1\n", result->arg);
        free(result);
        return 0;
    }
    free(result);
    printf("Passed too_little_whitespace\n");

    // Too many arguments
    printf("Testing too_many_args\n");
    FILE *too_many_args = fopen("scanfile_too_many_args", "r");
    result = calloc(1, sizeof(instruction));
    matches = scan_file(too_many_args, result);
    if (matches != -1)
    {
        printf("scan_file() test: Failed too many arguments.\nscan_file returned %d, should have returned -1\n", matches);
        printf("%s, %d\n", result->command, result->arg);
        free(result);
        return 0;
    }
    if (result->arg != -1)
    {
        printf("scan_file() test: Failed too many arguments\nArgument is %d, but should be -1\n", result->arg);
        free(result);
        return 0;
    }
    free(result);
    printf("Passed too_many_args\n");
    printf("==================\n==================\nPassed scan_file()\n==================\n==================\n");
}