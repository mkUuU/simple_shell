#ifndef _MAIN_H_
#define _MAIN_H_

/*Null pointer*/
#define NULL_PTR -1

/*specifier*/
#define WRONG_SPECIFIER -2

/**
 * get_char - allocates memory for a character
 * and a terminating NULL byte using usnmallon
 * The allocated mem shd hv two bytes: char, and termntng nullbyte.
 * @c: character to be stored in the allocated memory
 * Return: pointer to the allocated memory block or NULL if an error occured
 */
char *get_char(char c);

/**
 * get_string - allocated memory using malloc
 * @s: string to be stored in the allocated memory
 * Return: pointer to the allocated memory block or NULL if an error occured
 */
char *get_string(char *s);

/**
 * put_number - allocated memory for an integer
 * that stores the value in the allocated memory
 * @n: integer value to be stored in the memory block
 * Return: pointer to the allocated memory block or NULL if an error occured
 */
char *get_number(int n);

/**
 * print_arg - stores a single parameter
 * passed by reference into a memory block
 * @type: type of parameter
 * Return: pointer to the allocated memory block or NULL if an error occured
 */
char *get_arg(char type, ...);

/**
 * get_binary - converts the unsigned integer
 * to a binary string and returns a pointer to the string
 * @n: unsigned integerto be converted
 * Return: pointer to the binary string
 */
char *get_binary(unsigned int n);

/**
 * get_rev - reverses a string
 * @s: string to be reversed
 * Return: the reversed string
 */
char *get_rev(char *s);

/**
 * get_rot13 - applies rot13 cipher to  a string
 * @s: string to be encoded
 * Return: rot13-encoded string
 */
char *get_rot13(char *s);

char *str_concat(char *, char *);

char *string_nconcat(char *, char *, unsigned int);

int _strlen(char *);

int _printf(const char *, ...);

char *_strchr(char *s, char c);

int _atoi(char *s);

int _strcmp(char *, char *);

int _strcmp_n(char *, char *, int n);
#endif
