#include "main.h"
#include "lists.h"
#include "shell.h"

/**
 * _printenv - displays information about the environment variables
 * @params: pointer to a param_t structure containing the environment list.
 * Return: does not return to any value
 */

void _printenv(param_t *params)
{
	if (params->tokCount != 1)
	{
		_printf("env: %s: No such file or directory\n",
			params->args[1]);
		params->status = (2);
		return;
	}
	print_list_env(params->env_head);
	params->status = (0);
}

/**
 * print_list_env - prints the environment variables contained in the specified list
 * @head:  pointer to the head of the environment list
 */
void print_list_env(list_t *head)
{
	if (head)
	{
		print_list_env(head->next);
		if (head->str)
			_printf("%s=%s\n", head->str, head->val);
	}
}
