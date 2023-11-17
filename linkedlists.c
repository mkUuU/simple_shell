#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
#include "shell.h"
#include "main.h"

/**
 * list_len - returns the length of a linked list
 * @h: pointer to the head node of the list
 * Return: number of nodes in the list
 */
size_t list_len(list_t *h)
{
	size_t i;

	for (i = 0; h != 0; i++)
		h = h->next;
	return (i);
}

{
	int count;

	for (count = 0; h != 0; count++)
	{
		if (h->str == NULL)
			break;
		_printf("%s\n", h->str);
		h = h->next;
	}
	return (count);
}

/**
 * add_node - add a new node to the beginning of a linked list.
 * @head: pointer to the current head of the list
 * @str: key to searchfor in the list
 * @val: value to associate with the key
 * Return: pointer to the new head of the list
 */
list_t *add_node(list_t **head, char *str, char *val)
{
	list_t *new;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	new->str = _strdup(str);
	new->len = _strlen(new->str);
	new->val = _strdup(val);
	new->valLen = _strlen(val);
	new->next = *head;
	*head = new;

	return (new);
}

/**
 * get_node - searches for a node in a linked list based on a key
 * @head: pointer to the current head of the list
 * @str: key to search in the list
 * Return: pointer to the node containing
 * the matching key or NULL if no match was found
 */
list_t *get_node(list_t *head, char *str)
{
	list_t *h;

	if (!head)
		return (NULL);
	h = head;
	while (h)
	{
		if (!_strcmp(h->str, str))
			break;
		h = h->next;
	}
	return (h);
}

/**
 * free_list - frees memory allocated by a linked list
 * @head: pointer to the head of the linked list
 */
void free_list(list_t *head)
{
	list_t *ptr = head;

	while (head)
	{
		ptr = head->next;
		free(head->str);
		free(head->val);
		free(head);
		head = ptr;
	}
}
