#define _GNU_SOURCE
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "shell.h"
#include "main.h"
#define BUFFER_SIZE 4096
param_t *init_param(char **argv, char **env);

/**
 * main - entry point to simpleshell
 * @argc: num of command line arguments passed to the program
 * @argv: an array of NULL-terminated strings
 * representing the command line argument
 * @env: an array of NULL-terminated strings representing enviroment variables
 *
 * Return: 0 on success
 */
int main(int __attribute__((unused)) argc, char **argv, char **env)
{
	param_t *params = NULL;
	int cond = -2, status;
	unsigned int i;
	char *state = NULL;
	size_t size = BUFFER_SIZE;

	params = init_param(argv, env);
	if (!params)
		exit(-1);
	signal(SIGINT, sigint_handler);
	while (1)
	{
		if (cond == -1)
		{
			status = params->status;
			_printf("My_Shell :) ($) \n");
			free_params(params);
			return (status);
		}
		for (i = 0; i < BUFFER_SIZE; i++)
			(params->buffer)[i] = 0;
		params->tokCount = 0;
		if (isatty(STDIN_FILENO))
			_printf("My_Shell :) ($): ");

		cond = getline(&params->buffer, &size, stdin);
		params->lineCount++;
		if (cond == -1 && _strlen(params->buffer) == 0)
		{
			status = params->status;
			free_params(params);
			return (status);
		}
		state = NULL;
		params->nextCommand = _strtok(params->buffer, ";\n", &state);
		while (params->nextCommand)
		{
			params->tokCount = procss_str(params);
			if (params->tokCount == 0)
				break;
			run_command(params);
			for (i = 0; i < params->argsCap; i++)
			{
				free(params->args[i]);
				params->args[i] = NULL;
			}
			params->tokCount = 0;
			free(params->nextCommand);
			params->nextCommand = _strtok(params->buffer, ";\n",
						      &state);
		}
	}
}
/**
 * init_param - initiates parameter processing for the simple shell
 * @argv: an array of command line arguments passed to the program
 * @env: an array of environment variables
 * Return: parameter on success,NULL on failure
 */
param_t *init_param(char **argv, char **env)
{
	unsigned int i;
	char *eqs = NULL;
	param_t *params = malloc(sizeof(*params));

	if (!params)
		return (NULL);
	params->argsCap = 10;
	params->lineCount = 0;
	params->tokCount = 0;
	params->status = 0;
	params->argv = argv;
	params->nextCommand = NULL;
	params->buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!(params->buffer))
	{
		free(params);
		exit(-1);
	}
	for (i = 0; i < BUFFER_SIZE; i++)
		params->buffer[i] = 0;
	params->args = malloc(sizeof(char *) * params->argsCap);
	if (!(params->args))
	{
		free(params->buffer);
		free(params);
		exit(-1);
	}
	for (i = 0; i < params->argsCap; i++)
		params->args[i] = NULL;
	params->env_head = NULL;
	for (i = 0; env[i]; i++)
	{
		eqs = _strchr(env[i], '=');
		*eqs = '\0';
		params->env_head = add_node(&(params->env_head),
					    env[i], eqs + 1);
		if (!(params->env_head))
		{
			free(params->buffer);
			free(params->args);
			free_list(params->env_head);
			free(params);
			exit(-1);
		}
	}
	params->alias_head = NULL;
	return (params);
