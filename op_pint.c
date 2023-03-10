#include "monty.h"
/**
 * op_pint - prints the value at the top of the stack
 * @head: double pointer to head node of stack
 * @line_number: line number being interpreted from monty file
 *
 * Return: nothing
 */
void op_pint(stack_t **head, unsigned int line_number)
{
	if (!head || !*head) /* empty stack error */
		pint_error(head, line_number);
	printf("%d\n", (*head)->n);
}
