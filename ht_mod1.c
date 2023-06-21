#include "monty.h"

/**
 *  * f_mod - computes the rest of the division of the second
 *
 *   * top element of the stack by the top element of the stack
 *    * @head: stack head
 *     * @counter: line_number
 *      * Return: no return
 */

void f_mod(stack_t **head, unsigned int counter)

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
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	H = *head;
	if (H->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = H->next->n % H->n;
	H->next->n = aux;
	*head = H->next;
	free(H);
}
