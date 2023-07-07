#include "main.h"
/**
 * set_bit - Sets the value of a bit to 1 at a given index.
 * @n: Pointer to a number;
 * @index: index to replace in the number
 * Return: 1 if it worked, or -1 if an error occurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int m;

	if (index > sizeof(unsigned int) * 8)
		return (-1);
	m = 1;
	m = m << index;
	*n = ((*n) | m);
	return (1);
}
