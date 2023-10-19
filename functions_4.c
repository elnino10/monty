#include "monty.h"

/**
 * stack_func - prints the top
 * @head: pointer to stack head
 * @count: line count
 *
 * Return: nothing
*/
void stack_func(stack_t **head, unsigned int count)
{
	(void)head;
	(void)count;
	global_var.lifo = 0;
}

/**
 * queue_func - prints the top
 * @head: pointer to stack head
 * @count: line count
 *
 * Return: nothing
*/
void queue_func(stack_t **head, unsigned int count)
{
	(void)head;
	(void)count;
	global_var.lifo = 1;
}
