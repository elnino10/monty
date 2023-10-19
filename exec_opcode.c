#include "monty.h"

/**
 * exec_opcode - executes the opcode file
 * @content: file content
 * @head: head of linked stack_t list
 * @count: line count
 * @file: pointer to file to be executed
 *
 * Return: 0 when successful or 1 otherwise
 */
int exec_opcode(char *content, stack_t **head, unsigned int count, FILE *file)
{
	instruction_t instruction[] = {
		{"push", push_func}, {"pall", pall_func}, {"pint", pint_func},
		{"pop", pop_func}, {"swap", swap_func}, {"add", add_func},
		{"nop", nop_func}, {NULL, NULL}
	};
	char *_opcode;
	int i = 0;

	_opcode = strtok(content, " \n\t");
	if (_opcode && _opcode[0] == '#')
		return (0);
	global_var.arg = strtok(NULL, " \n\t");
	while (instruction[i].opcode && _opcode)
	{
		if (strcmp(_opcode, instruction[i].opcode) == 0)
		{
			instruction[i].f(head, count);
			return (0);
		}
		i++;
	}
	if (_opcode && instruction[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, _opcode);
		fclose(file);
		free(content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	return (1);
}

/**
 * free_stack - frees a stack_t list
 * @head: pointer to head node of list
 *
 * Return: nothing
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list
 * @head: pointer to the head node pointer
 * @n: value of member n to be added to list
 *
 * Return: address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		new_node->next = NULL;
	}
	else
	{
		(*head)->prev = new_node;
		new_node->next = *head;
		*head = new_node;
	}

	return (*head);
}

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
 * @head: pointer to the head node pointer
 * @n: member n to be added to list
 *
 * Return: address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *curr_node, *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	curr_node = *head;
	if (*head == NULL)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		while (curr_node->next != NULL)
		{
			curr_node = curr_node->next;
		}

		curr_node->next = new_node;
		new_node->prev = curr_node;
	}

	return (new_node);
}
