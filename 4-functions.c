#include "monty.h"
/**
 * usage_error - function that print an usage error message
 * Return: FAILURE
 */
void usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);

}

/**
 * open_error - function that print an open file error message
 *@file: file name
 * Return: FAILURE
 */
void open_error(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);

	exit(EXIT_FAILURE);

}
/**
 * push_error - handle push error
 * @fd: is a file desciptor
 * @line: is a buffer
 * @stack: is a stack or queue
 * @line_number: is a line command
 */
void push_error(FILE *fd, char *line, stack_t *stack, int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	fclose(fd);
	free(line);
	_free(stack);
	exit(EXIT_FAILURE);
}

/**
 * instr_error - Error handler
 * @fd: is a file descriptor
 * @line: is a buffer
 * @stack: is a stack or queue
 * @line_n: is a line command
 * @val: number
 */
void instr_error(FILE *fd, char *line, stack_t *stack, char *val, int line_n)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_n, val);
	fclose(fd);
	free(line);
	_free(stack);
	exit(EXIT_FAILURE);
}
