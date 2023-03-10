#include "monty.h"

/**
 * main - interpreter for monty
 * @argc: argument count
 * @argv: array of argument
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	FILE *file_ptr;
	char *line_buf = NULL, op_buf[20], val_buf[20];
	ssize_t bytes_read = 0, tokens = 0;
	size_t buf_size = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2 || !argv[1])
		usage_error90;
	stack_val.qu = 0;

	stack_val.file = argv[1];
	file_ptr = fopen(stack_val.file, "r");
	if (!file_ptr)

		file_error();
	while ((bytes_read = getline(&line_buf, &buf_size, file_ptr)) != -1)
	{
		line_number++;
		tokens = sscanf(line_buf, "%s %s", op_buf, val_buf);
		if (tokens > 2)
		{
			free(line_buf);
			usage_error();
		}

		free(line_buf);
		line_buf = NULL;
		stack_val.opcode = op_buf;
		if (tokens > 0 && stack_val.opcode[0] != '#')
			get_op_func(stack_val.opcode)(&stack, line_number);
		memset(op_buf, '\0', sizeof(op_buf));
		memset(val_buf, '\0', sizeof(val_buf));
	}
	free(line_buf);
	free_stack(&stack);
	fclose(file_ptr);
	return (0);
}
