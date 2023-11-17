#include "main.h"
#include "lists.h"
#include "shell.h"
#include <stdlib.h>

/**
 * _getenv - retrieves the value of a specific environment variable.
 * @name: name of the environment variable to retrieve
 * @params: pointer to a param_t structure containing the environment list
 *
 * Return: does not return to any value
 */

char *_getenv(char *name, param_t *params)
{
	list_t *ptr = params->env_head;

	while (ptr)
	{
		if (!_strcmp(name, ptr->str))
			return (_strdup(ptr->val));
		ptr = ptr->next;
	}
	return (NULL);
}
