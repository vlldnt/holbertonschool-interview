#include <stdlib.h>
#include <stddef.h>

int _putchar(char c);

/**
 * print_error_and_exit - print "Error\n" using _putchar and exit 98
 */
void print_error_and_exit(void)
{
	char *s = "Error\n";

	while (*s)
		_putchar(*s++);
	exit(98);
}

/**
 * print_ull - print an unsigned long long using _putchar
 * @n: number to print
 */
void print_ull(unsigned long long n)
{
	char buf[32];
	int i = 0;

	if (n == 0)
	{
		_putchar('0');
		return;
	}
	while (n > 0)
	{
		buf[i++] = '0' + (n % 10);
		n /= 10;
	}
	while (i--)
		_putchar(buf[i]);
}

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
		print_error_and_exit();
	}

	for (p = argv[1]; *p; p++)
	{
		if (*p < '0' || *p > '9')
		{
			print_error_and_exit();
		}
	}

	for (p = argv[2]; *p; p++)
	{
		if (*p < '0' || *p > '9')
		{
			print_error_and_exit();
		}
	}

	/* Convert strings to unsigned long long */
	n1 = strtoull(argv[1], NULL, 10);
	n2 = strtoull(argv[2], NULL, 10);

	/* Print the result */
	print_ull(n1 * n2);
	_putchar('\n');

	return (0);
}
