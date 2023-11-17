#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include "shell.h"
#include "main.h"
/**
 * _strcpy - copies a string from one memory location to another
 * @src: pointer to the source string
 * @dest: pointer to the destination memory address
 * where the copied string will be stored.
 *
 * Return: pointer to the destination memory address
 * where the copied string has been stored
 */
char *_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
		dest[i] = '\n';
	return (dest);
}

/**
 * _strcmp - compares two strings lexicographically
 * @s1: first string to be compared
 * @s2: seond string to be compared
 *
 * return:  An integer representing the comparison result,
 * with the following meanings:
 * negative number: s1 comes before s2 in the alphabetical order.
 * zero: s1 and s2 are equal.
 * positive number: s1 comes after s2 in the alphabetical order.
 */
int _strcmp(char *s1, char *s2)
{
	int res = 0;

	do {
		res = *s1 - *s2;
		if (*s1 == 0 || *s2 == 0)
			break;
		s1++;
		s2++;
	} while (res == 0);

	return (res);
}

/**
 * _strcmp_n - comparison of two strings based on the first n bytes
 * @s1: first string to be compared
 * @s2: second string to be compared
 * @n: number of bytes to compared
 * Return: An integer representing the comparison result,
 * with the following meanings:
 * negative number: The first mismatching byte in
 * s1 is less than the corresponding byte in s2.
 * zero: The first n bytes of s1 and s2 are identical.
 * positive number: The first mismatching byte in s1
 * is greater than the corresponding byte in s2.
 */
int _strcmp_n(char *s1, char *s2, int n)
{
	int i = 0, res = *s1 - *s2;

	while (i <= n)
	{
		res = *(s1++) - *(s2++);
		if (res != 0)
			break;
		i++;
	}

	return (res);
}

/**
 * _atoi - converts string into integer
 * @s: string to be converted
 * Return: integer value represented by first num of string
 */
int _atoi(char *s)
{
	int n, tmp, len, mul = 1;

	n = 0;
	tmp = 0;

	len = _strlen(s);
	len--;
	while (len >= 0)
	{
		tmp = n;
		n = n + (s[len] - '0') * mul;
		if (n < tmp || n > INT_MAX)
			return (-1);
		len--;
		mul *= 10;
	}
	return (n);
}
