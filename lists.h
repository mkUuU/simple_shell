#ifndef LISTSH
#define LISTSH

#include <unistd.h>

/**
 * struct list_s - singly linked list node
 * @str: string data
 * @val: associated value with the string value
 * @len: length of the string data
 * @valLen: length of the associated value string data
 * @next: pointer of the next node in the list
 */

typedef struct list_s
{
	char *str;
	char *val;
	unsigned int len;
	unsigned int valLen;
	struct list_s *next;
} list_t;

int _putchar(char c);

size_t print_list(list_t *h);

size_t list_len(list_t *h);

list_t *add_node(list_t **head, char *str, char *val);

void free_list(list_t *head);

list_t *get_node(list_t *head, char *str);

#endif
