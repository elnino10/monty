
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
		for (; global_var.arg[i] != '\0'; i++)
		{
			if (global_var.arg[i] > 57 || global_var.arg[i] < 48)
				flag = 1;
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
