#include "monty.h"
/**
 * exe_m - select the right function to execute
 * @stack: a pointer to the stack
 * @line_number: the number of lines
 * @tok_0: the instruction
 * @line_t: the buffer of getline
 * @fp: the file pointer id
 *
 * Return: 0 on success
 */
int exe_m(stack_t **stack, unsigned int line_number, char *tok_0,
	 char *line_t, FILE *fp)
{
	int i;
	int n_instructions = 11;

	instruction_t op_codes[] = {
	{"push", f_push},
	{"pall", f_pall},
	{"pint", f_pint},
	{"pop", f_pop},
	{"swap", f_swap},
	{"add", f_add},
	{"sub", f_sub},
	{"mul", f_mul},
	{"div", f_div},
	{"mod", f_mod},
	{"nop", f_nop}
};

for (i = 0; i < n_instructions; i++)
{
	if (strcmp(op_codes[i].opcode, tok_0) == 0)
	{
		if ((*stack == NULL || (*stack)->next == NULL) &&
			 (i > 4 && i < 10))
		{
			print_err(i - 1, line_number, "");
			free(line_t);
			fclose(fp);
			exit(EXIT_FAILURE);
		}
		if ((i == 8 || i == 9) && ((*stack)->n == 0))
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			free(line_t);
			fclose(fp);
			exit(EXIT_FAILURE);
		}
		op_codes[i].f(stack, line_number);
	}
}
return (0);
}
