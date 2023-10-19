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
