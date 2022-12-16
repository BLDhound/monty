#include "monty.h"

/**
 * op_swap - swaps the values of the top two elements of the stack
 * @head: double pointer to head node
 * @line_number: line number being interpreted from monty file
 *
 * Return: nothing, exit code EXIT_FAILURE
 */
void op_swap(stack_t **head, unsigned int line_number)
{
	int temp_n;

	if (!head || !*head || (*head)->next == NULL)
		swap_error(head, line_number);
	temp_n = (*head)->n;
	(*head)-> = (*head)->next->n;
	(*head)->next->n = temp_n;
}
