#ifndef monty_h
#define monty_h

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
}instruction_t;

extern stack_t *head;

typedef void (*op_func)(stack_t **, unsigned int);

void open_f(char *);
void read_f(FILE *);
int interp_line(char *, int, int);
void find_fun(char *opcode, char *value, int n_line, int format);
void free_all(void);
stack_t *new_create_node(int number);
void get_f(op_func, char *, char *, int, int);
void pint_stack(stack_t **node, unsigned int n_line);
void pop_stack(stack_t **node, unsigned int n_line);
void pall_stack(stack_t **stack, unsigned int n_line);
void push_stack(stack_t **node, unsigned int n_line);
void add_queue(stack_t **node, unsigned int n_line);
void pop_top(stack_t **stack, unsigned int n_line);


#endif /* monty_h */
