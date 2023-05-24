#include "monty.h"
/**
 * main - monty program
 * @argc: argument counter
 * @argv: argument value file name
 * Return: success or failure
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
