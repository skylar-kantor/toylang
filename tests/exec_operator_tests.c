#include "../exec.h"

int main(void)
{
    printf("testing add\n");
    for (int i = 0; i < 10000; i++)
    {
        for (int j = 0; j < 10000; j++)
        {
            Stack *test_stack = stack_init();
            stack_push(test_stack, i);
            stack_push(test_stack, j);
            int result = add(test_stack);
            if (result != i + j)
            {
                printf("Failed test for add. Got %d, should have gotten %d\n", result, i + j);
                stack_free(test_stack);
                return 0;
            }
            stack_free(test_stack);
        }
    }
    printf("passed add\n");

    printf("testing and\n");
    for (int i = 0; i < 10000; i++)
    {
        for (int j = 0; j < 10000; j++)
        {
            Stack *test_stack = stack_init();
            stack_push(test_stack, i);
            stack_push(test_stack, j);
            int result = and(test_stack);
            if (result != (i & j))
            {
                printf("Failed test for and. Got %d, should have gotten %d\n", result, i & j);
                printf("i=%d, j=%d\n", i, j);
                stack_free(test_stack);
                return 0;
            }
            stack_free(test_stack);
        }
    }
    printf("passed and\n");

    printf("testing nand\n");
    for (int i = 0; i < 10000; i++)
    {
        for (int j = 0; j < 10000; j++)
        {
            Stack *test_stack = stack_init();
            stack_push(test_stack, i);
            stack_push(test_stack, j);
            int result = nand(test_stack);
            if (result != ~(i & j))
            {
                printf("Failed test for nand. Got %d, should have gotten %d\n", result, ~(i & j));
                printf("i=%d, j=%d\n", i, j);
                stack_free(test_stack);
                return 0;
            }
            stack_free(test_stack);
        }
    }
    printf("passed nand\n");

    printf("testing or\n");
    for (int i = 0; i < 10000; i++)
    {
        for (int j = 0; j < 10000; j++)
        {
            Stack *test_stack = stack_init();
            stack_push(test_stack, i);
            stack_push(test_stack, j);
            int result = or (test_stack);
            if (result != (i | j))
            {
                printf("Failed test for or. Got %d, should have gotten %d\n", result, i | j);
                printf("i=%d, j=%d\n", i, j);
                stack_free(test_stack);
                return 0;
            }
            stack_free(test_stack);
        }
    }
    printf("passed or\n");

    printf("testing nor\n");
    for (int i = 0; i < 10000; i++)
    {
        for (int j = 0; j < 10000; j++)
        {
            Stack *test_stack = stack_init();
            stack_push(test_stack, i);
            stack_push(test_stack, j);
            int result = nor(test_stack);
            if (result != ~(i | j))
            {
                printf("Failed test for or. Got %d, should have gotten %d\n", result, ~(i | j));
                printf("i=%d, j=%d\n", i, j);
                stack_free(test_stack);
                return 0;
            }
            stack_free(test_stack);
        }
    }
    printf("passed nor\n");

    printf("testing xor\n");
    for (int i = 0; i < 10000; i++)
    {
        for (int j = 0; j < 10000; j++)
        {
            Stack *test_stack = stack_init();
            stack_push(test_stack, i);
            stack_push(test_stack, j);
            int result = xor(test_stack);
            if (result != (i ^ j))
            {
                printf("Failed test for xor. Got %d, should have gotten %d\n", result, i ^ j);
                printf("i=%d, j=%d\n", i, j);
                stack_free(test_stack);
                return 0;
            }
            stack_free(test_stack);
        }
    }
    printf("passed xor\n");

    printf("testing ls\n");
    for (int i = 0; i < 10000; i++)
    {
        for (int j = 0; j < 10000; j++)
        {
            Stack *test_stack = stack_init();
            stack_push(test_stack, i);
            stack_push(test_stack, j);
            int result = ls(test_stack);
            if (result != (j << i))
            {
                printf("Failed test for ls. Got %d, should have gotten %d\n", result, j << i);
                printf("i=%d, j=%d\n", i, j);
                stack_free(test_stack);
                return 0;
            }
            stack_free(test_stack);
        }
    }
    printf("passed ls\n");

    printf("testing rs\n");
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            Stack *test_stack = stack_init();
            stack_push(test_stack, i);
            stack_push(test_stack, j);
            int result = rs(test_stack);
            if (result != (j >> i))
            {
                printf("Failed test for ls. Got %d, should have gotten %d\n", result, j >> i);
                printf("i=%d, j=%d\n", i, j);
                stack_free(test_stack);
                return 0;
            }
            stack_free(test_stack);
        }
    }
    printf("passed rs\n");
    return 0;
}