#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * get_arg - formats and returns an argument based on the specified type specifier.
 * @type: a character indicating the desired formatting type (either 'c', 's', 'd', 'i', 'b', 'r', or 'R').
 * @...:zero or more additional arguments depending on the formatting type.
 *    Supported format types:

*'c': Treats a char argument as an integer and returns it as a string.
*'s': Converts a string argument to a char array and returns it as a string.
   * 'd': If the argument is an integer, returns it as a decimal string. If the argument is already a string, returns it unchanged.
   * 'i': Like 'd', but forces the output to be interpreted as a signed integer.
   * 'b': Converts an integer argument to a binary string.
   * 'r': Reverses a string argument and returns it as a new string.
   * 'R': Applies ROT13 encryption to a string argument and returns the encoded string.

 *
 * Return: an allocated string representing the formatted argument, or NULL if the type specifier is not supported.
 */


char *get_arg(char type, ...)
{
	va_list params;

	va_start(params, type);
	switch (type)
	{
	case 'c':
		return (get_char(va_arg(params, int)));
	case 's':
		return (get_string(va_arg(params, char*)));
	case 'd':
	case 'i':
		return (get_number(va_arg(params, int)));
	case 'b':
		return (get_binary(va_arg(params, int)));
	case 'r':
		return (get_rev(va_arg(params, char *)));
	case 'R':
		return (get_rot13(va_arg(params, char *)));
	default:
		return (NULL);
	}
}
