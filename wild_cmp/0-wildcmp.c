#include "holberton.h"

/**
 * wildcmp - compares two strings, where s2 may contain wildcards (*).
 * @s1: the string to compare against the pattern
 * @s2: the pattern string, may contain '*' matching any sequence
 *
 * Return: 1 if s1 matches s2, 0 otherwise.
 */
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '\0')
		return (*s1 == '\0');

	if (*s2 == '*')
		return (wildcmp(s1, s2 + 1) || (*s1 && wildcmp(s1 + 1, s2)));

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	return (0);
}
