#ifndef MONTY_HEADER
#define MONTY_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <ctype.h>

#define  _GNU_SOURCE

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * Description: opcode and functions for stacks and queues
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct global_var_s - global variables
 * @file: pointer to file
 * @arg: argument value
 * @content: line content
 * @lifo: flag
 * Description: carries values through the program
 */
typedef struct global_var_s
{
	FILE *file;
	char *arg;
	char *content;
	int lifo;
}  global_var_t;
extern global_var_t global_var;

/*Opcode execution file*/
int exec_opcode(char *content, stack_t **head, unsigned int count, FILE *file);
void free_stack(stack_t *head);
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);

/*functions_1 files*/
void push_func(stack_t **head, unsigned int count);
void pall_func(stack_t **head, unsigned int count);
void pint_func(stack_t **head, unsigned int count);
void pop_func(stack_t **head, unsigned int count);
void swap_func(stack_t **head, unsigned int count);

/*functions_2 files*/
void add_func(stack_t **head, unsigned int count);
void nop_func(stack_t **head, unsigned int count);
void sub_func(stack_t **head, unsigned int count);
void div_func(stack_t **head, unsigned int count);
void mul_func(stack_t **head, unsigned int count);

/*functions_3 files*/
void mod_func(stack_t **head, unsigned int count);
void pchar_func(stack_t **head, unsigned int count);
void pstr_func(stack_t **head, unsigned int count);
void rotl_func(stack_t **head, unsigned int count);
void rotr_func(stack_t **head, unsigned int count);

/*functions_4 files*/
void stack_func(stack_t **head, unsigned int count);
void queue_func(stack_t **head, unsigned int count);


#endif
