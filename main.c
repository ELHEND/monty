#include "monty.h"
/**
 *  * main - monty code interpreter
 *   * @argc: number of arguments
 *    * @argv: array of arguments
 *     *
 *      * Return: 0 on success, otherwise EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	bus_t bus = {NULL, NULL, NULL, 0};
	FILE *file;
	char *line = NULL;
	size_t line_size = 0;
	ssize_t read_line = 0;
	unsigned int line_no = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	bus.file = file;
	while ((read_line = getline(&line, &line_size, file)) != -1)
	{
		line_no++;
		bus.content = line;
		execute(line, &stack, line_no, file);
	}

	free_stack(stack);
	fclose(file);
	if (line)
		free(line);

	return (EXIT_SUCCESS);
}

