#include "monty.h"

/**
 * push_func - adds a node to stack_t list
 * @head: pointer to the head node pointer
 * @count: line count
 *
 * Return: nothing
 */
void push_func(stack_t **head, unsigned int count)
{
	int num, flag = 0, i = 0;

	if (global_var.arg)
	{
		if (global_var.arg[0] == '-')
			i++;
		while (global_var.arg[i] != '\0')
		{
			if (global_var.arg[i] > 57 || global_var.arg[i] < 48)
				flag = 1;
			i++;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(global_var.file);
			free(global_var.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(global_var.file);
		free(global_var.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	num = atoi(global_var.arg);
	if (global_var.lifo == 0)
		add_dnodeint(head, num);
	else
		add_dnodeint_end(head, num);
}

/**
 * pall_func - prints values in stack
 * @head: pointer to the head node pointer
 * @count: line count
 *
 * Return: nothing
 */
void pall_func(stack_t **head, unsigned int count)
{
	stack_t *temp;
	(void)count;

	temp = *head;
	if (temp == NULL)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint_func - prints stack top
 * @head: pointer to stack head pointer
 * @count: line count
 *
 * Return: nothing
 */
void pint_func(stack_t **head, unsigned int count)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		fclose(global_var.file);
		free(global_var.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * pop_func - prints the top
 * @head: stack head
 * @count: line_number
 *
 * Return: nothing
 */
void pop_func(stack_t **head, unsigned int count)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(global_var.file);
		free(global_var.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = temp->next;
	free(temp);
}

/**
 * swap_func - adds the top two elements of the stack.
 * @head: stack head
 * @count: line_number
 * Return: no return
 */
void swap_func(stack_t **head, unsigned int count)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		fclose(global_var.file);
		free(global_var.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	ptr = *head;
	temp = ptr->n;
	ptr->n = ptr->next->n;
	ptr->next->n = temp;
}
