#include "shell_header.h"

/**
 * exec_cmd - forks and executes commands
 * @args: array of command and arguments
 *
 * This function creates a child process using fork(), then attempts to execute
 * the command passed in the 'args' array. If the command fails to execute,
 * an error message is printed, and the child process exits with status 1.
 * If the fork() call fails, an error message is printed, and the process
 * exits with status 1.
 */

void exec_cmd(char *args[])
{
int status;
pid_t pid;

pid = fork();
if (pid == 0)
{
execvp(args[0], args);
printf("%s: %d: %s: command not found\n", shell, line_number, args[0]);
exit(1);
}
else if (pid > 0)
{
wait(&status);
}
else
{
perror("Forking process failed\n");
exit(1);
}
}


