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
		{NULL, NULL}
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
