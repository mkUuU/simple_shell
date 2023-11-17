#ifndef MY_SHELL_H
#define MY_SHELL_H
#define _GNU_SOURCE
#include <stdio.h>
#include "lists.h"
/**
 * struct param_s - structure that encapsulates all the
 * variables neededby simple shell
 * @argv: command line argument passed to the program from the main()function
 * @buffer: buffer for storing user input
 * @args: array of pointers to command line arguments
 * @nextCommand: a pointer to the next command to be processed
 * @argsCap: maximum capacity of the @args array
 * @lineCount: total number of lines of input received so far
 * @tokCount: number of tokens in each line input
 * @status: the exit status of the commands executed
 * @env_head: head of singly linked list of enviroment variables
 * @alias_head: head of a singly linked list of command aliases
 * Description: structs that hold all the variables that
 * need to be shared btw different functions within the simple shell
 */
typedef struct param_s
{
	char **argv;
	char *buffer;
	char **args;
	char *nextCommand;
	unsigned int argsCap;
	unsigned int lineCount;
	unsigned int tokCount;
	int status;
	list_t *env_head;
	list_t *alias_head;
} param_t;

/**
 * struct op - a builtin function in the siple shell
 * @name: string indicating the name of the bult-in function
 * @func: pointer to the function implementing the built-in functionality
 */
typedef struct op
{
	char *name;
	void (*func)(param_t *);
} op_t;

int procss_str(param_t *);

char *_strdup(char *);

char *_strcpy(char *dest, const char *src);

int _getline(param_t *);

int _strcmp(char *, char *);

int _strcmp_n(char *, char *, int n);

char *_strtok(char *str, char *delim, char **savePtr);

void run_command(param_t *);

void *_realloc(char **ptr, unsigned int old_size, unsigned int new_size);

void _printenv(param_t *);

void sigint_handler(int);

char *_getenv(char *name, param_t *params);

void _setenv(param_t *params);

void _unsetenv(param_t *params);

char *get_file(param_t *params);

void (*get_builtin(param_t *params))(param_t *);

void _myExit(param_t *params);

void _cd(param_t *params);

void _alias(param_t *params);

void set_alias(char *name, param_t *params);

void make_alias(char *name, char *val, param_t *params);

void print_alias(char *name, param_t *params);

void print_all_aliases(param_t *params);

void print_list_env(list_t *);

void print_list_alias(list_t *);

void free_params(param_t *params);

void write_error(param_t *params, char *msg);

void _clear(param_t *params);
#endif
