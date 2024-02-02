#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: current line number in the file
 *
 * Return: nothing
*/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n += (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
 * nop - Does nothing
 * @stack: double pointer to the top of the stack
 * @line_number: current line number in the file
 *
 * Return: nothing
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
