#include "monty.h"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_f(av[1]);
	return (0);
}

void add_queue(stack_t **node, unsigned int n_line)
{
	stack_t *aux;

	(void) n_line;
	if (node == NULL || *node == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (head == NULL)
	{
		head = *node;		
	}
	aux = head;
	while (aux->next != NULL)
	{
		aux = aux->next;
	}
	aux->next = *node;
	(*node)->prev = aux;
}

void push_stack(stack_t **node, unsigned int n_line)
{
	stack_t *aux;

	(void) n_line;
	if (*node == NULL || node == NULL)
        {
                exit(EXIT_FAILURE);
        }
	if (head == NULL)
        {
		head = *node;
		return;
        }
	aux = head;
        head = *node;
	head->next = aux;
	aux->prev = head;
}

void pall_stack(stack_t **stack, unsigned int n_line)
{
	stack_t *aux;

	(void) n_line;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	aux = *stack;
	while (aux != NULL)
	{
		printf("%d\n", aux->n);
	        aux = aux->next;
	}
}

void pop_stack(stack_t **node, unsigned int n_line)
{
	stack_t *aux;

	if (node == NULL || *node == NULL)
	{
		printf("L%d: can't pop an empty stack\n", n_line);
		exit(EXIT_FAILURE);
	}
	aux = *node;
	*node = aux->next;
	if (*node != NULL)
		(*node)->prev = NULL;
	free(aux);
}

void pint_stack(stack_t **stack, unsigned int n_line)
{
	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pint, stack empty\n", n_line);
	}
	printf("%d\n", (*stack)->n);
}
