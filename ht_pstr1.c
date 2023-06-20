#include "monty.h"

/**
 *  * f_pstr - The string at the top of the stack is printed
 *   * followed by a new
 *    * @head: stack head
 *     * @counter: line_number
 *      * Return: no return
 */

void f_pstr(stack_t **head, unsigned int counter)

{

	stack_t *H;
	(void)counter;

	H = *head;
	while (H)
	{
		if (H->n > 127 || H->n <= 0)
		{
			break;
		}
		printf("%c", H->n);
		H = H->next;
	}
	printf("\n");

}
