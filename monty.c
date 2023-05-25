#include "monty.h"
/**
 * main - entry point
 * @argc: argument counter
 * @argv: argument vector
 * Return: success || failure
 */
int main(int argc, char **argv)
{

	if (argc != 2)
	{
		 /** print usage error*/

		usage_error();
	}
	else
	{
		/** read the file and execute */
		execute(argv[1]);
	}

	return (EXIT_SUCCESS);

}
