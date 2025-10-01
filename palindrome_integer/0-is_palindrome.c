#include "palindrome.h"
#include <stdio.h>
#include <string.h>
/**
 * is_palindrome - check if an integer is a palindrome or not
 * @n: the integer to verify
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	char str_n[21];
	int i, len;

	sprintf(str_n, "%lu", n);
	len = strlen(str_n);

	for (i = 0; i < len / 2; i++)
	{
		if (str_n[i] != str_n[len - 1 - i])
			return (0);
	}

	return (1);
}
