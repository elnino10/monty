#include "monty.h"

/**
 * mod_func - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @head: pointer to stack head
 * @count: line count
 *
 * Return: nothing
 */
void mod_func(stack_t **head, unsigned int count)
{
	stack_t *ptr;
	int len = 0;
	int temp;

	ptr = *head;
	while (ptr)
	{
		ptr = ptr->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", count);
		fclose(global_var.file);
		free(global_var.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	ptr = *head;
	if (ptr->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		fclose(global_var.file);
		free(global_var.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = ptr->next->n % ptr->n;
	ptr->next->n = temp;
	*head = ptr->next;
	free(ptr);
}

/**
 * pchar_func - prints the char at the top of the stack
 * @head: pointer to stack head
 * @count: line count
 *
 * Return: nothing
 */
void pchar_func(stack_t **head, unsigned int count)
{
	stack_t *ptr;

	ptr = *head;
	if (!ptr)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
		fclose(global_var.file);
		free(global_var.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (ptr->n > 127 || ptr->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
		fclose(global_var.file);
		free(global_var.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", ptr->n);
}
