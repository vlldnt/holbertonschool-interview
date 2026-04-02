#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * check_words - checks if the substring starting at @s matches
 *               all words in @words (each used exactly once)
 * @s: pointer to the current position in the string
 * @words: array of words to match
 * @nb_words: number of words
 * @word_len: length of each word
 *
 * Return: 1 if all words are matched, 0 otherwise
 */
static int check_words(char const *s, char const **words,
	int nb_words, int word_len)
{
	int i, j, found;
	int used[nb_words];

	for (i = 0; i < nb_words; i++)
		used[i] = 0;

	for (i = 0; i < nb_words; i++)
	{
		found = 0;
		for (j = 0; j < nb_words; j++)
		{
			if (!used[j] &&
				strncmp(s + i * word_len, words[j], word_len) == 0)
			{
				used[j] = 1;
				found = 1;
				break;
			}
		}
		if (!found)
			return (0);
	}
	return (1);
}

/**
 * find_substring - finds all starting indices in @s where a concatenation
 *                  of all words in @words (each used exactly once) occurs
 * @s: the string to search in
 * @words: array of words to concatenate
 * @nb_words: number of words in @words
 * @n: pointer to store the number of indices found
 *
 * Return: array of starting indices, or NULL if none found
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int i, count, word_len, total_len;
	int *result;

	*n = 0;
	if (!s || !words || nb_words == 0)
		return (NULL);

	word_len = strlen(words[0]);
	total_len = word_len * nb_words;

	result = malloc(sizeof(int) * strlen(s));
	if (!result)
		return (NULL);

	count = 0;
	for (i = 0; s[i] && (int)strlen(s + i) >= total_len; i++)
	{
		if (check_words(s + i, words, nb_words, word_len))
		{
			result[count] = i;
			count++;
		}
	}

	if (count == 0)
	{
		free(result);
		return (NULL);
	}

	*n = count;
	return (result);
}
