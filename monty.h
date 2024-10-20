#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
	char *arg;
} instruction_t;

int my_readline(char **buff, size_t *size_buff, FILE *stream);
void execute_instruct(instruction_t *instruction, stack_t **stack, size_t line_number);
void push(stack_t **stack, char *arg);
void pall(stack_t **stack);
void test(stack_t **stack);
instruction_t *create_instruct(char *opcode, void *arg);
void process_file(FILE *file, stack_t **stack);
int is_number(const char *str);

#endif
