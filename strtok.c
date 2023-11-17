#include <stdlib.h>
#include "shell.h"
#include "main.h"

/**
 * isDelim - determines wherether a character is delimiters
 * @c: character to be checked
 * @del: set of delimiters characters
 * Return: 1 if character is delimiter, 0 otherwise
 */

int isDelim(char c, char *del)
{
	while (*del)
	{
		if (c == *del)
			return (1);
		del++;
	}
	return (0);
}

/**
 * _strtok - splits a string into tokens using a specific set of delimeters
 * @str: string to be split
 * @del: delimiters used to separate tokens
 * @savePtr: pointer to a state object that stores information about the splittng process
 * Return: nxt token found in the string, NULL if no tokens remain
 */

char *_strtok(char *str, char *del, char **savePtr)
{
	char *ptr, *modifier, *end;
	int quoteFound = 0;

	if (*savePtr)
		ptr = *savePtr;
	else
		ptr = str;
	end = ptr;
	while (*end)
		end++;
	while (*ptr && isDelim(*ptr, del))
		ptr++;
	modifier = ptr;
	if (*ptr == '\0')
	{
		return (NULL);
	}
	if (*ptr == '\'')
	{
		ptr++;
		modifier = _strchr(ptr, '\'');
		if (!modifier)
		{
			_printf("no matching quote found!\n");
			exit(-1);
		}
		*modifier = '\0';
		*savePtr = modifier + 1;
		return (_strdup(ptr));
	}
	while (*modifier)
	{
		if (*modifier == '\'')
			quoteFound = 1;
		if (isDelim(*modifier, del) && quoteFound == 0)
			break;
		modifier++;
	}
	if (*modifier == '\0')
		*savePtr = modifier;
	else
		*savePtr = modifier + 1;
	*modifier = '\0';
	return (_strdup(ptr));
}
