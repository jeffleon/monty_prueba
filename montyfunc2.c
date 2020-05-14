#include "monty.h"
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *copy;
	unsigned int numero = (*stack)->n;

	pop(stack, 9); /*verificar numerito*/
	copy = *stack;
	copy->n = numero + copy->n;
}
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

}
/**
 * free_dlistint - singly linked list
 * @head: string - (malloc'ed string)
 * Return: a number
 */
void free_dlistint(stack_t *head)
{
        stack_t *temp;

        while (head)
        {
                temp = head->next;
                free(head);
                head = temp;
        }
}

