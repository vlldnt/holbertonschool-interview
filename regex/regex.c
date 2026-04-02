#include "stdio.h"
#include <regex.h>
/**
 * regex_match - checks if a string matches a regex pattern
 * @str: the string to check
 * @pattern: the pattern to match against
 * (supports '.'  one and '*' many carachters
 *
 * Return: 1 if @str matches @pattern, 0 otherwise
 */

int regex_match(char const *str, char const *pattern)
{
	const char *star = NULL;
	const char *match = str;

	while (*str)
	{
		if (*str == *pattern || *pattern == '.')
		{
			str++;
			pattern++;
		}
		else if (*pattern == '*')
		{
			/* wildcard found: save its position and current str */
			star = pattern;
			match = str;
			pattern++;
		}
		else if (star)
		{
			/* mismatch but a previous '*' exists: backtrack */
			pattern = star + 1;
			match++;
			str = match;
		}
		else
			return (0);
	}
	/* skip any trailing stars in the pattern */
	while (*pattern == '*')
		pattern++;

	return (*pattern == '\0');
}