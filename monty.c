#include "monty.h"
#include <stdio.h>
#include <stdbool.h>

int line_number = 0;

int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	size_t read;
	char *opcode;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != (size_t)-1)
	{
		opcode = strtok(line, " \n\t\r");

		if (opcode != NULL && opcode[0] != '#')
		{
			if (strcmp(opcode, "push") == 0)
			{
				int value = 0;
				char *arg = strtok(NULL, " \n\t\r");

				if (arg == NULL || !is_number(arg))
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					free_stack(&stack);
					fclose(file);
					free(line);
					exit(EXIT_FAILURE);
				}
				value = atoi(arg);
				push(&stack, value);
			}
			else if (strcmp(opcode, "pall") == 0)
			{
				pall(&stack);
			}
			else if (strcmp(opcode, "pint") == 0)
			{
				pint(&stack);
			}
			else if (strcmp(opcode, "pop") == 0)
			{
				pop(&stack);
			}
			else if (strcmp(opcode, "swap") == 0)
			{
				swap(&stack);
			}
			else if (strcmp(opcode, "add") == 0)
			{
				add(&stack);
			}
			else if (strcmp(opcode, "nop") == 0)
			{
				/* No operation is needed for the nop opcode*/
			}
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
				free_stack(&stack);
				fclose(file);
				free(line);
				exit(EXIT_FAILURE);
			}
		}
		line_number++;
	}
	fclose(file);
	free(line);
	free_stack(&stack);
	return (EXIT_SUCCESS);
}
