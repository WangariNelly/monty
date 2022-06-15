#include "monty.h"

/**
  * get_tokens - tokenizes text lines intro strings
  * @string: input to tokenize
  * @my_tokens: tokens
  * Return: tokenized input
  */
void get_tokens(char *string, char **my_tokens)
{
	int i = 0;
	char *token;
	char *separators = " \t\n";

	if (my_tokens == NULL)
		exit(EXIT_FAILURE);
	token = strtok(string, separators);
	while (token != NULL)
	{
		my_tokens[i] = token;
		i++;
		token = strtok(NULL, separators);
	}
	my_tokens[i] = NULL;
}
