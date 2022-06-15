#include "monty.h"
/**
 * is_integer - Finds whether  mumber is an integer
 * @tokens: string to be analized to find if it is a integert
 *
 * Return: 1 if it is a number, 0 if not.
 */
int is_integer(char *tokens)
{
	int i = 0;

	if (tokens == NULL)
		return (0);
	if (tokens[i] == '-')
		i++;
	for (; tokens[i] != '\0'; i++)
	{
		if (tokens[i] < 48 || tokens[i] > 57)
			return (0);
	}

	global_number = atoi(tokens);
	return (1);
}
