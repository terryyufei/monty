#include "monty.h"

/**
 * _free - free stack
 * @stack: stack
 */

void _free(stack_t *stack)
{
stack_t *list = NULL;

	list = stack;

	if (list != NULL)
	{
		_free(list->next);
		free(list);
	}

}

/**
 * clean_stack - Free all and close files
 * @stack: Stack
 */

void clean_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (tmp)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
	fclose(cmd.fd);
	free(cmd.line);
}
