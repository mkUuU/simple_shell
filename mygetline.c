#include <unistd.h>
#include <stdlib.h>
#include "shell.h"
#include "main.h"
#define BUFFER_SIZE 4096
#define READ_SIZE 1024

/**
 * rlLine - reallocates a line buffer
 * @line: pointer to buffer to be reallocated
 * @oldSize: size of the old buffer
 * @newSize: desired size of new buffer
 * Return: new allocated buffer with the specified size
 */
char *rlLine(char **line, unsigned int oldSize, unsigned int newSize)
{
	char *newLine = NULL;
	unsigned int i;

	newLine = malloc(newSize);
	if (newLine)
	{
		for (i = 0; i < oldSize; i++)
			newLine[i] = (*line)[i];
		free(*line);
		*line = newLine;
	}
	return (newLine);
}
/**
 * _getline - reads a line of characters from stdin
 * @params: input parameters for the function
 * Return: number of characters read
 */
int _getline(param_t *params)
{
	char *line = NULL;
	static unsigned int bufSize = BUFFER_SIZE;
	char *writeH = line;
	unsigned int len;

	line = malloc(BUFFER_SIZE);
	do {
		len = read(0, writeH, BUFFER_SIZE);
		if (len == 0)
			break;
		writeH += len;
		if (writeH >= (line + BUFFER_SIZE - 1 - READ_SIZE))
		{
			line = rlLine(&line, bufSize, bufSize * 2);
			bufSize *= 2;
		}
	} while (*(writeH - 1) != '\n');

	free(params->buffer);
	params->buffer = line;
	if (len == 0)
		return (-1);
	return (_strlen(params->buffer));
}
