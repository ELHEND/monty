#include "monty.h"
/**
 *  * f_swap - Calculate the sum of the top two elements within the stack.
 *   * @head: stack head
 *    * @counter: line_number
 *     * Return: no return
 */
void f_swap(stack_t **head, unsigned int counter)
{
	stack_t *H;
	int len = 0, aux;

	H = *head;
	while (H)
	{
		H = H->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	H = *head;
	aux = H->n;
	H->n = H->next->n;
	H->next->n = aux;


}
