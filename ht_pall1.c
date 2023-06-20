#include "monty.h"
/**
 *  * f_pall - prints the stack
 *   * @head: stack head
 *    * @counter: no used
 *     * Return: no return
 *     */
void f_pall(stack_t **head, unsigned int counter)

{

	stack_t *H;
	(void)counter;

	H = *head;
	if (H == NULL)
		return;
	while (H)
	{
		printf("%d\n", H->n);
		H = H->next;
	}
}
