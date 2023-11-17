#include <stdlib.h>

/**
 * str_concat - joins two strings and returns a pointer to the concatenated result
 * @z1: first string argument
 * @z2: second string argument
 * Return: NULL on failure, pointer to the dynamically allocated memory containing the concatenated stringon success
 */
char *str_concat(char *z1, char *z2)
{
	char *ptr;
	int i = 0;
	int j = 0;
	int x = 0;

	if (z1 == NULL)
	{
		z1 = "";
	}
	if (z2 == NULL)
	{
		z2 = "";
	}
	while (z1[i] != '\0')
	{
		i++;
	}
	while (z2[j] != '\0')
	{
		j++;
	}
	ptr = malloc((i * sizeof(char)) + (j * sizeof(char)) + 1);
	if (ptr == NULL)
	{
		return (NULL);
	}
	for (i = 0; z1[i] != '\0'; i++)
	{
		ptr[i] = z1[i];
		x++;
	}
	for (j = 0; z2[j] != '\0'; j++)
	{
		ptr[x] = z2[j];
		x++;
	}
	ptr[x] = '\0';
	return (ptr);
}
/**
 * string_nconcat - concatenatedtwo strings and returns a pointer to the resulting string
 * @z1: first string argument
 * @z2: second string argument
 * @n: number of bytes taken from z2 for the concatenation
 * Return: NULL on failure, pointer to the dynamically allocated memory containing the concatenated stringon success
 */
char *string_nconcat(char *z1, char *z2, unsigned int n)
{
	char *ptr;
	unsigned int i = 0;
	unsigned int j = 0;

	if (z1 == NULL)
	{
		z1 = "";
	}
	if (z2 == NULL)
	{
		z2 = "";
	}
	while (z1[i] != '\0')
	{
		i++;
	}
	while (z2[j] != '\0')
	{
		j++;
	}
	if (n > j)
	{
		n = j;
	}
	ptr = malloc(sizeof(char) * (n + i) + 1);
	if (ptr == NULL)
	{
		return (NULL);
	}
	for (i = 0; z1[i] != '\0'; i++)
	{
		ptr[i] = z1[i];
	}
	for (j = 0; j < n; j++)
	{
		ptr[i + j] = z2[j];
	}
	ptr[i + j] = '\0';
	return (ptr);
}
/**
 *_strlen - returns the length of a string
 *@s: string whose length will be calculated
 *Return: 0 if the string is NULL, length of the string without the NULL terminator
 */
int _strlen(char *s)
{
	int length = 0;

	if (s == NULL)
	{
		return (0);
	}

	for (length = 0; s[length] != '\0'; length++)
		;
	return (length);
}

/**
 * _strdup - duplicates a string by allocating a new block of memory and copying the contents of the original string into it.
 * @str: strig to be duplicated
 * Return: pointer to the newly allocated memory block containing the duplicates of the string, NULL if there is insufficient memory available to perform the operation
 */
char *_strdup(char *str)
{
	int len = 0;
	char *ptr = NULL;

	if (!str)
		return (NULL);
	while (*str)
	{
		len++;
		str++;
	}
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr)
	{
		while (len >= 0)
			*(ptr + len--) = *(str--);
	}
	return (ptr);
}

/**
 * _strchr - first occurrence of a character in the string
 * @s: starting position in the string where search begins
 * @c: character to search for
 * Return:  pointer to the beginning of the memory region where the character was found, or NULL if the character is not present in the string
 */
char *_strchr(char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	if (c == '\0')
		return (&s[i]);
	return (0);
}
