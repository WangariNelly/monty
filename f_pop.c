#include "monty.h"
/**
 * f_pop - erases a node
 * @head: head of the stack
 * @line_number: line of the comand
 *
 * Return: On success 1.
 * On error, -1 is returned.
 */
void f_pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp, *aux, *node;

	line_number = line_number;

	temp = *head;
	if (temp != NULL)
	{
		aux = temp->next;
		node = temp;
		if (aux != NULL)
			aux->prev = NULL;
		free(node);
		*head = aux;
	}
}
