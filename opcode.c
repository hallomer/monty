#include "monty.h"

/**
 * push - Pushes an integer to the stack
 * @stack: double pointer to the top of the stack
 * @line_number: current line number in the file
 *
 * Return: nothing
*/
void push(stack_t **stack, unsigned int line_number)
{
	char *argument;
	stack_t *new_node;
	int i;

	argument = strtok(NULL, " ");
	if (argument == NULL)
	{
		printf("L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	for (i = 0; argument[i] != '\0'; i++)
	{
		if (!isdigit(argument[i]) && argument[i] != '-')
		{
			printf("L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(argument);
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall - Prints all the values on the stack
 * @stack: double pointer to the top of the stack
 * @line_number: current line number in the file
 *
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
