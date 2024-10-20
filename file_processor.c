#include "monty.h"
#include <string.h>

/**
 * process_file - process the instructions from a file
 * @file: pointer to a file to be processed
 * @stack: pointer to a pointer at the top of the stack
 *
 * Description: Reads the file line by line,
 * tokenizes each line to extract the opcode,
 * creates an instruction and executes it.
 *
 * Return: void
 */

void process_file(FILE *file, stack_t **stack)
{
    char *buff = NULL;
    size_t len = 0;
    int line_number = 1;
    instruction_t *instruct; /* <--- Declaration moved to the top */

    /* Read the file line by line */
    while (my_readline(&buff, &len, file) != -1)
    {
        char *opcode = strtok(buff, "\t\n");

        /* if line is not empty, process the opcode */
        if (opcode)
        {
            /* Handle the push opcode separately to check for the argument */
            if (strcmp(opcode, "push") == 0)
            {
                char *arg = strtok(NULL, "\t\n ");
                if (!arg || !is_number(arg)) /* Check if the argument is a valid number */
                {
                    fprintf(stderr, "L%d: usage: push integer\n", line_number);
                    free(buff);
                    exit(EXIT_FAILURE);
                }
                /* Pass the opcode and argument to create the instruction */
                instruct = create_instruct(opcode, arg); /* <--- Removed redeclaration */
                execute_instruct(instruct, stack, line_number);
                free(instruct);
            }
            else
            {
                /* create an instruction for the extracted opcode */
                instruct = create_instruct(opcode, NULL); /* <--- Removed redeclaration */

                /* if opcode is invalid or unknown */
                if (!instruct)
                {
                    fprintf(stderr, "L%d: unknown instruction %s", line_number, opcode);
                    free(buff);
                    exit(EXIT_FAILURE);
                }

                /* execute the valid instruction on the stack */
                execute_instruct(instruct, stack, line_number);

                /* Free the dynamically allocated instruction after execution */
                free(instruct);
            }
        }
        /* Increment the line number after each line processed */
        line_number++;
    }
    free(buff); /* freeing the buffer after processing all lines */
}

/**
 * create_instruct - create an instruction structure
 * @opcode: The opcode string
 * @arg: The argument for the instruction
 *
 * Return: a pointer to the newly created instruction structure.
 */

instruction_t *create_instruct(char *opcode, void *arg)
{
	instruction_t *instruction = malloc(sizeof(instruction_t));

	if (!instruction)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	instruction->opcode = strdup(opcode);
	instruction->arg = arg;

	return (instruction);
}
