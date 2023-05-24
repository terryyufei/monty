#include "monty.h"

/* Function to print the value at the top of the stack */
void pint(stack_t **stack)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/* Rest of the code remains the same as before */

