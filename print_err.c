#include "monty.h"
/**
  * print_err - Print an error msg
  * @i: error msg to be printed
  * @l_num: number of the line
  * @txt: text to be printed for the error
  * Return: Nothing
  */
void print_err(int i, int l_num, char *txt)
{
	if (i == 0)
		fprintf(stderr, "USAGE: monty file\n");
	if (i == 1)
		fprintf(stderr, "Error: Can't open file <%s>\n", txt);
	if (i == 2)
		fprintf(stderr, "L%d: unknown instruction %s\n", l_num, txt);
	if (i == 3)
		fprintf(stderr, "Error: malloc failed\n");
	if (i == 4)
		fprintf(stderr, "L%d: can't add, stack too short\n", l_num);
	if (i == 5)
		fprintf(stderr, "L%d: can't sub, stack too short\n", l_num);
	if (i == 6)
		fprintf(stderr, "L%d: can't mul, stack too short\n", l_num);
	if (i == 7)
		fprintf(stderr, "L%d: can't div, stack too short\n", l_num);
	if (i == 8)
		fprintf(stderr, "L%d: can't mod, stack too short\n", l_num);
}
