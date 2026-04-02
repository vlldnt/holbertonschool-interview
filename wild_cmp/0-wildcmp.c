#include <stdlib.h>
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
	char *star = NULL;
	char *match = s1;

	while (*s1)
	{
		if (*s1 == *s2)
		{
			/* characters match: advance both pointers */
			s1++;
			s2++;
		}
		else if (*s2 == '*')
		{
			/* wildcard found: save its position and current s1 */
			star = s2;
			match = s1;
			s2++;
		}
		else if (star)
		{
			/* mismatch but a previous '*' exists: backtrack */
			s2 = star + 1;
			match++;
			s1 = match;
		}
		else
			return (0);
	}
	/* skip any trailing stars in the pattern */
	while (*s2 == '*')
		s2++;

	return (*s2 == '\0');
}
