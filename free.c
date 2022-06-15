#include "monty.h"
/**
 * free_stack_t - frees a list
 * @head: a pointer to a list
 *
 * Return: nothing.
 */
void free_stack_t(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
