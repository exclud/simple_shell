#include "shell_header.h"

/**
 * main - main shell program
 *
 * This is the main function of the shell program. It initializes variables,
 * checks if the input is from a terminal or not, and processes commands.
 * If the input is not from a terminal, it reads one command and processes it.
 * If the input is from a terminal, it enters an infinite loop, reading and
 * processing commands until the 'exit' command is entered.
 *
 * @argc: number of command-line arguments
 * @argv: array of command-line arguments
 *
 * Return: 0 on successful exit or 1 on error.
 */
int main(int argc, char **argv)
{
char *command = NULL;
size_t n = 0;
char *args[MAX_NUM_ARGS + 1];

(void)argc;
shell = *argv;

if (!isatty(STDIN_FILENO))
{
if (getline(&command, &n, stdin) == -1)
{
perror("Error: unable to read command with getline()\n");
return (1);
}
command[strcspn(command, "\n")] = '\0';
parse_cmd(command, args);
exec_cmd(args);
free(command);
return (0);
}
while (1)
{
printf(">> ");
if (getline(&command, &n, stdin) == -1)
{
perror("Error: unable to read command with getline()\n");
break;
}
command[strcspn(command, "\n")] = '\0';
parse_cmd(command, args);

if (strcmp(args[0], "exit") == 0)
{
break;
}
exec_cmd(args);
}
free(command);
return (0);
}
