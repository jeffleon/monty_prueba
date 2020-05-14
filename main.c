#include "monty.h"
linehead args;

int main(int argc, char *argv[])
{

	ssize_t lines = 0;
	FILE *file_monty;
	char *longitud;
	int length = 0;
	int i;
	size_t line_size = 0;
	args.counter = 0,
	args.head = NULL;
	args.matrix = NULL;
	args.line = NULL;
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_monty = fopen(argv[1],"r");
	if (file_monty == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while(lines >= 0)
	{
		args.matrix = NULL;
		args.line = NULL;
		lines = getline(&args.line, &line_size,file_monty);
                args.counter += 1;
		args.matrix = tokenfunc();
		free(args.line);
		free(args.matrix);
	}
//	free_dlistint(args.head);
	fclose(file_monty);
	return (0);
}
