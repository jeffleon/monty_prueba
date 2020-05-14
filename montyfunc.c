#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	addnode(stack,line_number);
}
stack_t *addnode(stack_t **stack, unsigned int line_number)
{
	stack_t *copy = *stack;
        stack_t *new_node;

	if (stack == NULL)
                return (NULL);
        new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
                exit(EXIT_FAILURE);
	}
        new_node->n = atoi(args.matrix[1]);
        new_node->next = copy;
        new_node->prev = NULL;
        *stack = new_node;
        if (copy != NULL)
                copy->prev = new_node;
        else
                new_node->prev = NULL;
	return (new_node);
	/*******liberar memoria*******/
}
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *copy = *stack;

	printf("%d\n", copy->n);
}
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *copy = *stack;

	*stack = copy->next;
	(*stack)->prev = NULL;
	free(copy);
}
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *copy = *stack;
	int aux;

	aux = copy->next->n;
	copy->next->n = copy->n;
	copy->n = aux;
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *copy = *stack;

	printf("entre a pall\n");
	for (;copy;copy=copy->next)
		printf("%d\n", copy->n);
}
