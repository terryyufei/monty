#include "monty.h"
/**
 * _isdigit - Checks if is a digit  0 .. 9
 * Return: 0 or 1
 * @c: Value
 **/
int _isdigit(char *c)
{
	char *tmp = c;

	if (c == NULL)
		return (0);
	if (*tmp == '-')
		tmp++;

	for (; *tmp != '\0'; tmp++)
	{
		if ((*tmp < '0' || *tmp > '9'))
		{
			return (0);
		}
	}
	return (1);
}

