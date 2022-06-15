#include "monty.h"
/**
 * control_monty - Control the flow of the project.
 * @argc: number of command line arguments.
 * @argv: array containing the program command line arguments
 * Return: always 0
 */
int control_monty(int argc, char *argv[])
{
	FILE *fp;
	char *line_txt = NULL, *my_tokens[1024];
	int chars_read = 1, valid;
	unsigned int line = 0;
	size_t buf_size = 0;
	stack_t *head = NULL;

	if (argc == 2)
	{	fp = fopen(argv[1], "r+");
		if (fp == NULL)
		{	print_err(1, 0, argv[1]);
			fclose(fp);
			exit(EXIT_FAILURE);
		}
		for (line = 0; chars_read > 0 ;)
		{	line++;
			chars_read = getline(&line_txt, &buf_size, fp);
			if (chars_read > 0)
			{	get_tokens(line_txt, my_tokens);
				valid = validate_tokens(my_tokens);
				if (valid == 0)
				{	print_err(2, line, my_tokens[0]);
					fclose(fp);
					free(line_txt);
					free_stack_t(head);
					exit(EXIT_FAILURE); }
				else if (valid == 1)
				{
					if (is_integer(my_tokens[1]) == 1)
						exe_m(&head, line, my_tokens[0], line_txt, fp);
				}
				else if (valid > 1 && valid < 12)
					exe_m(&head, line, my_tokens[0], line_txt, fp);
			}
		}
	fclose(fp);
	}
	free(line_txt);
	free_stack_t(head);
	return (0);
}
