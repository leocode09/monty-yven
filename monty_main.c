#include "monty.h"

/**
 * main - Entry gate of the monty bytecode interpreter
 * @argc: number of arguments to inputed
 * @argv: an array of the arguments
 *
 * Return: EXIT_SUCCESS if successful, otherwise EXIT_FAILURES
 */

int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	process_file(file, &stack);

	fclose(file);
	return (EXIT_SUCCESS);
}
