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

/**
 * pstr_func - prints the string starting at the top of the stack
 * @head: pointer to stack head
 * @count: line count
 *
 * Return: nothing
 */
void pstr_func(stack_t **head, unsigned int count)
{
	stack_t *top;
	(void)count;

	top = *head;
	while (top)
	{
		if (top->n > 127 || top->n <= 0)
		{
			break;
		}
		printf("%c", top->n);
		top = top->next;
	}
	printf("\n");
}

/**
 *rotl_func- rotates the stack to the top
 *@head: pointer to stack head
 *@count: line count
 *
 *Return: nothing
 */
void rotl_func(stack_t **head, unsigned int count)
{
	stack_t *ptr = *head, *temp;
	(void)count;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	temp = (*head)->next;
	temp->prev = NULL;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = *head;
	(*head)->next = NULL;
	(*head)->prev = ptr;
	(*head) = temp;
}

/**
 *rotr_func- rotates the stack to the bottom
 *@head: pointer to stack head
 *@count: line count
 *
 *Return: nothing
 */
void rotr_func(stack_t **head, unsigned int count)
{
	stack_t *temp;
	(void)count;

	temp = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = *head;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*head)->prev = temp;
	(*head) = temp;
}
