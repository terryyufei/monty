#include "monty.h"
cmd_t cmd = {NULL, NULL};
/**
 * execute - function that read the file and execute the monty byte
 *@argv: the file ;
 */

void execute(char *argv)
{
	int c_line = 0, r = 0;
	size_t bufsize = 0;
	char *token = NULL, *val = NULL;
	stack_t *stack = NULL;

	/** open file mod read in global variable*/
	cmd.fd = fopen(argv, "r");
	if (cmd.fd)
	{
		while (getline(&cmd.line, &bufsize, cmd.fd) != -1)
		{
			c_line++;
			token = strtok(cmd.line, " \n\t\r");
			if (token == NULL)
			{
				free(token);
				continue;
			}
			else if (*token == '#')/** is comment*/
				continue;
			val = strtok(NULL, " \n\t\r");
			r = get_opc(&stack, token, val, c_line);
			if (r == 1) /** get_opt return 1 when the value is not digit */
				push_error(cmd.fd, cmd.line, stack, c_line); /** print push error*/
			else if (r == -1) /** get_opt return -1if not the instruction */
				instr_error(cmd.fd, cmd.line, stack, token, c_line);
					/**print instruction error*/
		}
		free(cmd.line);
		_free(stack);/** free all*/
		fclose(cmd.fd); /** close file*/
	}
	else
	{
		/** print open error*/
		open_error(argv);

	}
}


/**
 * get_opc - function that get the option function
 * @stack: stack or queue
 * @arg: commande
 * @val: value
 * @line_number: iline number
 * Return: 0 in success 1 and -1 error
 */
int get_opc(stack_t **stack, char *arg, char *val, int line_number)
{
	int i = 0;

	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", nop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{NULL, NULL}
	};

	while (op[i].opcode)
	{
		if (!strcmp(arg, op[i].opcode))
		{
			if (!strcmp(arg, "push"))
			{
				if (_isdigit(val) == 1)
					value = atoi(val);
				else
					return (1);/** if not digit*/
			}
			op[i].f(stack, (unsigned int)line_number);
			break;
		}
		i++;
	}
	if (!op[i].opcode)
		return (-1);/** if not the commande*/

	return (0);
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


