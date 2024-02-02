#include "monty.h"

/**
 * pchar - Prints the character at the top of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: current line number of the opcode being executed
 *
 * Return: nothing
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}

/**
 * pstr - Prints the string starting at the top of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the opcode being executed
 *
 * Return: nothing
*/
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL && current->n != 0 && current->n >= 0 && current->n <= 127)
	{
		printf("%c", current->n);
		current = current->next;
	}

	printf("\n");
}