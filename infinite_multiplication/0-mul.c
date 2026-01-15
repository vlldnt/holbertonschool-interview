#include <stdio.h>
#include <stdlib.h>

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	char *p;
	unsigned long long n1, n2;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	for (p = argv[1]; *p; p++)
	{
		if (*p < '0' || *p > '9')
		{
			printf("Error\n");
			exit(98);
		}
	}

	for (p = argv[2]; *p; p++)
	{
		if (*p < '0' || *p > '9')
		{
			printf("Error\n");
			exit(98);
		}
	}

	/* Convert strings to unsigned long long */
	n1 = strtoull(argv[1], NULL, 10);
	n2 = strtoull(argv[2], NULL, 10);

	/* Print the result */
	printf("%llu\n", n1 * n2);

	return (0);
}
