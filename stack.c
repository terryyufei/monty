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


