#include "monty.h"
char **tokenfunc()
{
	char delim[3] = " \n\t";
	char *token = NULL;
	int i = 0;
	int matrixsize = 0;
	char *aux = NULL;
	char **matrix = NULL;

	token = strtok(args.line, delim);
	matrixsize = 3;
        matrix = malloc(sizeof(char *) * matrixsize);

	if (matrix == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0;token != NULL; i++)
	{
		matrix[i] = token;
		printf("%s\n", matrix[i]);
		token = strtok(NULL, delim);
	}
	matrix[i] = NULL;
	return (matrix);
}

void matrixfree()
{
	int i = 0;
	char **repit = args.matrix;

	if (args.matrix && args.matrix[0])
	{
		for (i = 0; i < 3; i++)
			free(repit[i]);
		free(repit);
	}
}

int funchandler()
{
	instruction_t key[] = {{"push", push},
			       {"pint", pint},
			       {"pop", pop},
			       {"swap", swap},
			       {"add", add},
			       {"nop", nop},
			       {"pall", pall},
			       {NULL, NULL}};
	int i = 0;

	for (i = 0; key[i].opcode != NULL; i++)
	{
		if (strcmp(key[i].opcode, args.matrix[0]) == 0)
		{
			key[i].f(&(args.head), args.counter);
			break;
		}
	}
	if (i == 7)
	{
		printf("L%d: unknown instruction %s\n", args.counter, args.matrix[0]);
		exit(EXIT_FAILURE);
	}
	return (0);
}
