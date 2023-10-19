#include "monty.h"

/**
 * add_func - adds the top two elements of the stack.
 * @head: stack head
 * @count: line_number
 *
 * Return: nothing
 */
void add_func(stack_t **head, unsigned int count)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		fclose(global_var.file);
		free(global_var.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	ptr = *head;
	temp = ptr->n + ptr->next->n;
	ptr->next->n = temp;
	*head = ptr->next;
	free(ptr);
}

/**
 *nop_func- nothing
 *@head: pointer to stack head
 *@count: line count
 *
 *Return: nothing
 */
void nop_func(stack_t **head, unsigned int count)
{
	(void) count;
	(void) head;
}

/**
 *sub_func- sustration
 *@head: stack head pointer
 *@count: line count
 *
 *Return: nothing
 */
void sub_func(stack_t **head, unsigned int count)
{
	stack_t *temp;
	int diff;
	int node;

	temp = *head;
	for (node = 0; temp != NULL; node++)
		temp = temp->next;
	if (node < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", count);
		fclose(global_var.file);
		free(global_var.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	diff = temp->next->n - temp->n;
	temp->next->n = diff;
	*head = temp->next;
	free(temp);
}
