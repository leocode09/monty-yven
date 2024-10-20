#include "monty.h"

/**
 * push - pushes an element onto the stack
 * @stack: Doube pointer to top node of the stack
 * @arg: the argument to push
 *
 * Description: creates a new node with the argument as it's value
 * and pushes them.
 */

void push(stack_t **stack, char *arg)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(arg);
	new_node->prev = NULL;

	if (*stack)
	{
		(*stack)->prev = new_node;
		new_node->next = *stack;
	}
	else
	{
		new_node->next = NULL;
	}

	*stack = new_node;
}

/**
 * pall - it prints all the values on the stack
 * @stack: a double pointer to top of the stack
 *
 * Descrition: it prints to the console the values
 * of each node of the stack.
 */

void pall(stack_t **stack)
{
	stack_t *tmp;
	if (stack == NULL || *stack == NULL)
		return;

	tmp = *stack;

	while (tmp)
	{
		printf("%d", tmp->n);
		if (tmp->next)
			printf(",");
		tmp = tmp->next;
	}
	printf("\n");
}

int is_number(const char *str)
{
	int i;
	if (str == NULL)
	       	return (0);
	for (i = 0; str[i]; i++)
	{
		if (str[i] == '-' && i == 0) /* Handle negative numbers */
			continue;
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}
