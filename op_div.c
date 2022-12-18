#include "monty.h"

/**
 * op_div - divides values
 * @head: double pointer to head node
 * @line_number: line number being interpreted from Monty file
 */
void op_div(stack_t **head, unsigned int line_number)
{
	int first, second;

	if (!head || !*head || !(*head)->next)
		div_error(head, line_number);
	if ((*head)->n == 0)
		zero_error(head, line_number);

	first = (*head)->n;
	second = (*head)->next->n;
	*head = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
	(*head)->n = second / first;
}
