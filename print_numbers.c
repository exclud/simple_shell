#include "shell_header.h"

/**
 * print_num - print the numbers from 0 - 9
 *
 * This function iterates through the numbers from 0 to 9 and prints each
 * number followed by a newline character.
 *
 * Return: void
 */
void print_num(void)
{
int i;

for (i = 0; i < 10; i++)
{
printf("%d", i);
}
printf("\n");
}

