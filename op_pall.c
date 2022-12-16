#include "monty.h"

/**
 * op_pall - prints all the values on the stack, starting from the top
 * @stack: duoble pointer to head note
 * @line_number: line number where opcodes was encountered
 *
 * Return: nothing
 */
void op_pall(stack_t *8stack, unisgned int line_number)
{
	stack_t *node = NULL;

	if (!line_number)

		return;
	node = *stack;
	while (node)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}
