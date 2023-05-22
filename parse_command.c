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
	char *comment_st;
	int j = 0;

	/* Find the start of a comment, if any, and terminate the string there */
	comment_st = strchr(command, '#');
	if (comment_st != NULL)
	{
		*comment_st = '\0';
	}
	while (token != NULL && j < MAX_NUM_ARGS)
	{
		args[j] = token;
		token = strtok(NULL, " ");
		j++;
	}
	args[j] = NULL;
}

