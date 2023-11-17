#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "shell.h"
#include "lists.h"
#include "main.h"
/**
 * run_command - seaches for a mommand in various directories and executes it
 * @params: parameters for the command execution
 */
void run_command(param_t *params)
{
	char *exeFile = NULL;
	pid_t pid;
	void (*builtin)(param_t *);

	builtin = get_builtin(params);
	if (builtin)
	{
		builtin(params);
		return;
	}
	exeFile = get_file(params);
	if (!exeFile)
	{
		return;
	}
	pid = fork();
	if (pid < 0)
	{
		free_params(params);
		exit(98);
	}
	else if (pid == 0)
	{
		execve(exeFile, params->args, NULL);
	}
	else
	{
		wait(&params->status);
		params->status = WEXITSTATUS(params->status);
		free(exeFile);
	}
}
