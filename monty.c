#include "monty.h"

instruction_t instructions[] = {
	{"push", push},
	{"pall", pall},
	{"pall", pint},
	{"pop", pop},
	{"swap", swap},
	{"add", add},
	{"nop", nop},
	{"sub", sub},
	{"div", divide},
	{"mul", mul},
	{"mod", mod},
};

/**
 * main - Entry point of Monty interpreter
 * @argc: arguments count
 * @argv: array of arguments
 * Return: EXIT_SUCCESS or EXIT_FAILURE
*/
int main(int argc, char *argv[])
{
	char *filename;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	filename = argv[1];
	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		return (EXIT_FAILURE);
	}

	read_file(file);

	fclose(file);

	return (EXIT_SUCCESS);
}

/**
 * read_file - Reads instructions from a file and executes them
 * @file: The file pointer to read instructions from
 *
 * Return: nothing
*/
void read_file(FILE *file)
{
	stack_t *stack = NULL, *current, *next;
	char instruction[256], *opcode;
	unsigned int line_number = 1, i;

	while (fgets(instruction, sizeof(instruction), file) != NULL)
	{
		instruction[strcspn(instruction, "\n")] = '\0';

		opcode = strtok(instruction, " ");

		if (opcode != NULL && opcode[0] != '#')
		{
			for (i = 0; i < sizeof(instructions) / sizeof(instruction_t); i++)
			{
				if (strcmp(opcode, instructions[i].opcode) == 0)
				{
					instructions[i].f(&stack, line_number);
					break;
				}
			}

			if (i == sizeof(instructions) / sizeof(instruction_t))
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			}
		}

		line_number++;
	}

	current = stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
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
