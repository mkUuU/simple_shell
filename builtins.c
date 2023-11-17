#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"
#include "lists.h"
#include "main.h"

/**
 * get_builtin - retrieves a pointer to a built-in function
 * based on the parameters provided in the param_t structure.
 * @params: pointer to the param_t structure containing the command parameters.
 * Return: returns a pointer to the
 * built-in function if found, or NULL if not found
 */

void (*get_builtin(param_t *params))(param_t *)
{
	op_t ops[] = {
		{"exit", _myExit},
		{"clear", _clear},
		{"env", _printenv},
		{"setenv", _setenv},
		{"cd", _cd},
		{"unsetenv", _unsetenv},
		/*{"alias", _alias},*/
		{NULL, NULL},
	};
	op_t *op = ops;

	while (op->name)
	{
		if (!_strcmp(params->args[0], op->name))
			return (op->func);
		op++;
	}
	return (NULL);
}
