#include "shell_header.h"

/**
 * parse_cmd - parse command into arguments
 * @command: command string
 * @args: array of arguments
 *
 * This function tokenizes the command string using spaces as delimiters,
 * storing each token in the 'args' array. The process continues until either
 * the maximum number of allowed arguments (MAX_NUM_ARGS) is reached or
 * the end of the command string is encountered. Comments starting with '#'
 * are ignored.
 */
void parse_cmd(char *command, char *args[])
{
char *token = strtok(command, " ");
char *comment_start;
int i = 0;

/* Find the start of a comment, if any, and terminate the string there */
comment_start = strchr(command, '#');
if (comment_start != NULL)
{
*comment_start = '\0';
}

while (token != NULL && i < MAX_NUM_ARGS)
{
args[i] = token;
token = strtok(NULL, " ");
i++;
}
args[i] = NULL;
}

