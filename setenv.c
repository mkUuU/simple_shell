#include <stdlib.h>
#include "shell.h"
#include "main.h"
#include "lists.h"

/**
 * _setenv - sets an environment variable with the given name and value
 *
 * @params: parameters for setting the enviroment variable
*/
void _setenv(param_t *params)
{
	char *tmp = NULL;
	char *name = params->args[1], *value = params->args[2];
	list_t *h = params->env_head;

	if (params->tokCount != 3)
	{
		params->status = 0;
		return;
	}
	while (h)
	{
		if (_strcmp(name, h->str) == 0) /* variable environ exists */
		{
			tmp = h->val;
			free(tmp);
			h->val = _strdup(value);
			if (!h->val)
			{
				write(STDERR_FILENO, "setenv malloc error\n", 18);
				exit(-1);
			}
			h->valLen = _strlen(value);
			params->status = 0;
			return;
		}
		h = h->next;
	}
	params->env_head = add_node(&(params->env_head), name, value);
	params->status = 0;
}
/**
 * _unsetenv - removes an environment variable with the given name
 *
 * @params: parameters for removing the enviroment variable
*/
void _unsetenv(param_t *params)
{
	char *name = params->args[1];
	list_t *prev = NULL, *h = params->env_head;

	if (params->tokCount != 2)
	{
		params->status = 0;
		return;
	}
	while (h)
	{
		if (_strcmp(name, h->str) == 0) /* variable environ exists */
		{
			if (h == params->env_head)
				params->env_head = h->next;
			else
				prev->next = h->next;
			free(h->str);
			free(h->val);
			free(h);
			params->status = 0;
			return;
		}
		prev = h;
		h = h->next;
	}
	params->status = 0;
}
