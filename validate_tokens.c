#include "monty.h"
/**
  * validate_tokens - Tells if a token is valid for execution in montly
  * @tokens: tokens for analize
  * Return: -1 if empty line, i + 1 if function found, and 0 if not found
  */
int validate_tokens(char **tokens)
{
	int j;
	char *f[11] = {"push", "pall", "pint", "pop", "swap", "add", "sub",
			"mul", "div", "mod", "nop"};

	if (tokens[0] == NULL)
		return (14);
	for (j = 0; j < 12; j++)
	{
		if (strcmp(tokens[0], f[j]) == 0)
		{
			/* Function found */
			return (j + 1);
		}
	}
	/* Function not found */
	return (0);
}
