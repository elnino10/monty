#define _POSIX_C_SOURCE 200809L
#include "monty.h"

global_var_t global_var = {0, NULL, NULL, NULL};

/**
 * main - program entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 when successful
 */
int main(int argc, char *argv[])
{
	FILE *file;
	ssize_t n_read = 1;
	char *content = NULL;
	unsigned int count;
	size_t file_size = 0;
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	global_var.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (n_read > 0)
	{
		n_read = getline(&content, &file_size, file);
		global_var.content = content;
		count++;
		if (n_read > 0)
		{
			exec_opcode(content, &head, count, file);
		}
		free(content);
	}
	free_stack(head);
	fclose(file);

	return (0);
}
