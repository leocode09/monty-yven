#include "monty.h"
#include <stdlib.h>

/**
 * my_readline - func that reads a line from the file line getline function
 * @buff: a pointer to a buffer containing line to be read
 * @size_buff: pointer to a size of a buff
 * @stream: file stream to be read
 *
 * Return: returns the  number of character read,
 * otherwise returns -1
 */

int my_readline(char **buff, size_t *size_buff, FILE *stream)
{
	char *new_buff;
	int c;
	int len = 0;
	size_t buff_size = 0;

	if (!buff || !size_buff || !stream)
		return (-1);
	/* reading the character one by one */
	while ((c = fgetc(stream)) != EOF)
	{
		if (len >= (int) (*size_buff) - 1)
		{
			buff_size += 128;
			new_buff = realloc(*buff, buff_size);

			if (!new_buff)
				return (-1);
			*buff = new_buff;

			*size_buff = buff_size; /* updating the size*/

		}
		(*buff)[len++] = (char)c;

		if (c == '\n')
			break;
	}
	/* if no character read */
	if (len == 0)
		return (-1);
	/* null-terminate the string */
	(*buff)[len] = '\0';

	return (len);/*returning the number of char read */
}

/**
 * execute_instruct - it executes the instruction by calling a function
 * @instruction: an instruction or opcode to be executed.
 * @stack: a double pointer to the top of the stack
 * @line_number: number of line where instruction is .
 *
 * Description: it executes a function called based on the instruction.
 */

void execute_instruct(instruction_t *instruction, stack_t **stack, size_t line_number)
{
	/* if the opcode is "push", call the push function*/
	if (strcmp(instruction->opcode, "push") == 0)
		push(stack, instruction->arg);

	/* if the opcode is "pall", call the pall function*/
	if (strcmp(instruction->opcode, "pall") == 0)
	{
		pall(stack);
	}

	/* if the opcode is "test", call the test function*/
	if (strcmp(instruction->opcode, "test") == 0)
	{
		test(stack);
	}
	(void)line_number;
}

void test(stack_t **stack)
{
	printf("test\n");
	pall(stack);
}
