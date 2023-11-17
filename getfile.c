#include <stdlib.h>
/**
 * move_left - removes leading zeros from a binary number represented as a string
 * @a: buffer containing the binary number
 * @size: size of the buffer
 * @num: number of digits in the binary number
 * Return: the modified buffer with leading zeros removed
 */
char *move_left(char *a, int size, int num)
{
	int i;
	char *ptr;

	for (i = 0, ptr = (a + size - num); i < num; i++, ptr++)
		*(a + i) = *ptr;
	*(a + num) = '\0';
	return (a);
}

/**
 * get_binary - convert an usigned integer to a binary string
 * @n: unsigned integer to convert
 * Return: returns pointer to the binary string representationof the input number
 */

char *get_binary(unsigned int n)
{
	char *ptr = NULL;
	unsigned int i, num = 0, size = (0);

	if (n == 0)
	{
		ptr = malloc(2);
		if (ptr)
		{
			ptr[0] = '0';
			ptr[1] = '\0';
		}
		return (ptr);
	}
	size = sizeof(int) * 8 + 1;
	ptr = malloc(size);
	if (ptr)
	{
		for (i = 0; i < size; i++)
		{
			ptr[i] = '0';
		}
		ptr[size - 1] = '\0';

		i = size - 2;
		while (n != 0)
		{
			ptr[i] = n % 2 == 0 ? '0' : '1';
			num++;
			n = n / 2;
			i--;
		}
		num++;
		ptr = move_left(ptr, size, num);
	}
	return (ptr);
}

/**
 * get_char - copies a character and returns a pointer to the copied character
 * @c: character to copy
 * Return: returns a pointer to the copied character
 */
char *get_char(char c)
{
	char *ptr = NULL;

	ptr = malloc(2);
	if (ptr == NULL)
	{
		return (NULL);
	}
	ptr[0] = c;
	ptr[1] = '\0';
	return (ptr);
}

/**
 * get_string - returns a newly allocated and copied string.
 * @s: string to be copied
 * Return: returns a pointer to the newly allocated and copied string or NULL if the string is NULL
 */
char *get_string(char *s)
{
	char *ptr = NULL;
	int i, j;

	if (s == NULL)
	{
		ptr = malloc(7);
		if (ptr == NULL)
			return (NULL);
		ptr[0] = '(';
		ptr[1] = 'n';
		ptr[2] = 'u';
		ptr[3] = 'l';
		ptr[4] = 'l';
		ptr[5] = ')';
		ptr[6] = '\0';
		return (ptr);
	}
	for (i = 0; s[i] != '\0'; i++)
	{
		;
	}
	ptr = (char *)malloc(i * sizeof(char) + 1);
	if (ptr == NULL)
	{
		return (NULL);
	}
	for (j = 0; j < i; j++)
	{
		ptr[j] = s[j];
	}
	ptr[j] = '\0';
	return (ptr);
}

/**
 * get_number - stores an integer as a string in a dynamically allocated memory block
 * @n: integer to be converted into a string
 *
 * Return: returns a pointer to the dynamically allocated memory block containing the string representation of the integer or NULL on error
 */
char *get_number(int n)
{
	int i, len = 0, tmp;
	char *buf = NULL;
	/*determines the number of bytes required to store an integer as a string*/
	tmp = n;
	while (tmp >= 10 || tmp <= -10)
	{
		tmp /= 10;
		len++;
	}
	len++;
	if (n < 0)
		len++;
	buf = malloc(sizeof(char) * (len + 1));
	if (buf)
	{
		buf[len] = '\0';
		if (n < 0)
		{
			buf[0] = '-';
		}
		i = len - 1;
		while (n >= 10 || n <= -10)
		{
			tmp = (n % 10) >= 0 ? n % 10 : -(n % 10);
			buf[i] = tmp + '0';
			i--;
			n /= 10;
		}
		tmp = (n % 10) >= 0 ? n % 10 : -(n % 10);
		buf[i] = tmp + '0';
	}
	return (buf);
}
