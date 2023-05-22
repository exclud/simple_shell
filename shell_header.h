#ifndef SHELL_HEADER_H
#define SHELL_HEADER_H

#define MAX_NUM_ARGS 10

/* Standard Headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

/* Function Prototypes */
void parse_cmd(char *command, char *args[]);
void exec_cmd(char *args[]);
void print_num(void);

/* Global variables */
char *shell;
int line_number;

#endif /* SHELL_HEADER_H */

