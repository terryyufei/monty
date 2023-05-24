#include <stdbool.h>
#include <stddef.h>

bool is_number(const char *str)
{
	int i;

	if (str == NULL || *str == '\0')
	{
		return false;
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (false);
		}
	}
	return (true);
}

