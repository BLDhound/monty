#include "monty.h"

/**
 * op_add - adds the values of the top two elements of the stack
 * @head: double pointer to head node
 * @line_number: line number being interpreted from monty file
 *
 * Description: result is stored in 2nd top element
 * Return: nothing, print exit code EXIT_FAILURE
 */
void op_add(stack_t **head, unsigned int line_number)
{
	int first, second;

	if (!head || !*head || !(*head)->next)
		add_error(head, line_number);
	first = (*head)->n;
	second = (*head)->next->n;
	*head = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
	(*head)->n = first + second;
}
