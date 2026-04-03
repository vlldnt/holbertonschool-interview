#include <stdio.h>
#include <stdlib.h>

#include "regex.h"

#define TEST_MATCH(s, p) \
	do {                                                                       \
		int res = regex_match(s, p);                                           \
		printf("%s -> %s = %d\n", s, p, res);                                  \
	} while (0)

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	TEST_MATCH("A", "A");
	TEST_MATCH("A", "");
	TEST_MATCH("", "A");
	TEST_MATCH("", "");
	TEST_MATCH("AA", "A");
	TEST_MATCH("A", "AA");

	TEST_MATCH("A", "A*");
	TEST_MATCH("AA", "A*");
	TEST_MATCH("AAAAA", "A*");
	TEST_MATCH("AAAAAAAAAA", "A*");
	TEST_MATCH("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", "A*");
	TEST_MATCH("", "A*");
	TEST_MATCH("B", "A*");
	TEST_MATCH("AB", "A*");
	TEST_MATCH("BA", "A*");

	TEST_MATCH("AB", "AB");
	TEST_MATCH("AB", "AB*");
	TEST_MATCH("ABB", "AB*");
	TEST_MATCH("A", "AB*");
	TEST_MATCH("A", "ABCDEFGHIJKLMNOPQRSTUVWXYZ*");
	TEST_MATCH("AZ", "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	TEST_MATCH("AZ", "ABCDEFGHIJKLMNOPQRSTUVWXYZ*");
	TEST_MATCH("AFJLOSWZ", "ABCDEFGHIJKLMNOPQRSTUVWXYZ*");
	TEST_MATCH("AFJPLOSWZ", "ABCDEFGHIJKLMNOPQRSTUVWXYZ*");

	TEST_MATCH("AB", "A.");
	TEST_MATCH("ABC", "A.C");
	TEST_MATCH("ABC", "A..");
	TEST_MATCH("ABC", "A.");
	TEST_MATCH("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "A...................");
	TEST_MATCH("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "A..................Z");
	TEST_MATCH("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "A.................Z");

	TEST_MATCH("", ".");
	TEST_MATCH("", ".*");
	TEST_MATCH("A", ".*");
	TEST_MATCH("AA", ".*");
	TEST_MATCH("AABB", ".*");
	TEST_MATCH("Lorem ipsum dolor si amet", ".*");

	TEST_MATCH("ABC", "ZA.");
	TEST_MATCH("ABC", "ZAB.");
	TEST_MATCH("ABC", "ZABC.");
	TEST_MATCH("ABC", "Z.");
	TEST_MATCH("ABC", ".*");
	TEST_MATCH("ABC", "..");
	TEST_MATCH("ABC", "....................");
	TEST_MATCH("", "....................");

	TEST_MATCH("H", "H");
	TEST_MATCH("HH", "H");
	TEST_MATCH("HH", "H*");
	TEST_MATCH("HHHHHHHHHHHHHHHHH", "H*");

	TEST_MATCH("Holberton", ".*");
	TEST_MATCH("Alex", ".*");
	TEST_MATCH("Guillaume", ".*");
	TEST_MATCH("Julien", ".*");

	TEST_MATCH("Holberton", "Z*H.*");
	TEST_MATCH("Holberton", "Z*H.*olberton");
	TEST_MATCH("Holberton", "Z*H.*o.");
	TEST_MATCH("Holberton", "Z*H.*o");
	TEST_MATCH("Holberton", "holberton");
	TEST_MATCH("Holberton", ".olberton");

	TEST_MATCH("Lorem ipsum dolor si amet", "Lorem ipsum dolor si amet");
	TEST_MATCH("Lorem ipsum dolor si amet", "Lor.*m ipsum dolor si amet");
	TEST_MATCH("Lorem ipsum dolor si amet", "Lore.*m ipsum dolor si amet");
	TEST_MATCH("Lorem ipsum dolor si amet", ".*Lorem ipsum dolor si amet");
	TEST_MATCH("Lorem ipsum dolor si amet", "Lorem ipsum dolor si amet.*");
	TEST_MATCH("Lorem ipsum dolor si amet", ".Lorem ipsum dolor si amet.");
	TEST_MATCH("Lorem ipsum dolor si amet", ".Lorem..ipsum dolor si amet.*");
	TEST_MATCH("Lorem ipsum dolor si amet", ".Lorem.ipsum dolor si amet.*");
	TEST_MATCH("Lorem ipsum dolor si amet", ".Lorem ipsum dolor si amet.");
	TEST_MATCH("Lorem ipsum dolor si amet", ".Lorem .* dolor si amet.");
	TEST_MATCH("Lorem ipsum dolor si amet", ".Lorem ... dolor si amet.");
	TEST_MATCH("Lorem ipsum dolor si amet", ".orem ipsum dolor si amet");
	TEST_MATCH("Lorem ipsum dolor si amet", "Lorem ipsum dolor si ame.");

	TEST_MATCH("!H@o#l$b%e^r&t(o)n_", "!.@.#.$.%.^.&.(.)._");

	return (EXIT_SUCCESS);
}
