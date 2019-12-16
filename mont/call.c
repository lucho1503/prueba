#include "monty.h"
stack_t *head = NULL;

void free_all(void)
{
	stack_t *aux;
	if (head == NULL)
		return;
	while (head != NULL)
	{
		aux = head;
		head = head->next;
		free(aux);
	}
}

stack_t *new_create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(node));
	if (node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

void get_f(op_func f, char *opcode, char *value, int n_line, int format)
{
	stack_t *node;
	int flag, i;
	
	flag = 1;
	if (strcmp(opcode, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value += 1;
			flag = -1;
		}
		if (value == NULL)
		{
			printf("L%d: usage: op_push integer\n", n_line);
			exit(EXIT_FAILURE);
		}
		for (i = 0; value[i] != '\0'; i++)
		{
			if (isdigit(value[i]) == 0)
			{
				printf("L%d: usage: push integer\n", n_line);
				exit(EXIT_FAILURE);
			}
		}
		node = new_create_node(atoi(value) * flag);
		if (format == 0)
			f(&node, n_line);
		if (format == 1)
			add_queue(&node, n_line);
	}
	else
		f(&head, n_line);
}
 
