#include "regex.h"

/**
 * regex_match - checks if a string matches a regex pattern
 * @str: the string to check
 * @pattern: the pattern to match against (supports '.' and '*')
 *
 * The matching rules are:
 *   '.' matches any single character
 *   '*' matches zero or more occurrences of the preceding character
 *
 * Return: 1 if @str matches @pattern, 0 otherwise
 */
int regex_match(char const *str, char const *pattern)
{
	int first_match;

	if (*pattern == '\0')
		return (*str == '\0');

	first_match = (*str != '\0') &&
		(*pattern == '.' || *pattern == *str);

	if (*(pattern + 1) == '*')
		return (regex_match(str, pattern + 2) ||
			(first_match && regex_match(str + 1, pattern)));

	return (first_match && regex_match(str + 1, pattern + 1));
}
