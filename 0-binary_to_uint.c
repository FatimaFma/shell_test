#include "main.h"

/**
 * binary_to_uint - Converters a binary number to an unsigned integer
 * @b: String representing a binary number
 * Return: The converted number
 * 0 if b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int l;
	unsigned int i;
	unsigned int j;
	unsigned int sum;
	unsigned int pow;
	int base;

	base = 2;
	sum = 0;
	pow = 1;
	if (b == NULL)
		return (0);
	for (l = 0; b[l] != '\0'; l++)
		;
	if (l == 1 && (b[0] == '0' || b[0] == '1'))
		return ((b[0] - 48));
	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
		for (j = l - 1; j > 0; j--)
			pow = pow * base;
		sum = sum + (pow * (b[i] - 48));
		l--;
		pow = 1;
	}
	return (sum);
}
