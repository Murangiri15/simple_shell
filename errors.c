#include "shell.h"

/**
 * _eputs - prints an input string
 * @str: string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int x = 0;

	if (!str)
		return;
	while (str[x] != '\0')
	{
		_eputchar(str[x]);
		x++;
	}
}

/**
 * _eputchar - writes the character c to stderr
 * @a: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char a)
{
	static int x;
	static char buf[WRITE_BUF_SIZE];

	if (a == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(2, buf, x);
		x = 0;
	}
	if (c != BUF_FLUSH)
		buf[x++] = a;
	return (1);
}

/**
 * _putfd - writes the character c to given fd
 * @a: The character to print
 * @ac: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char a, int ac)
{
	static int x;
	static char buf[WRITE_BUF_SIZE];

	if (a == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(ac, buf, x);
		x = 0;
	}
	if (c != BUF_FLUSH)
		buf[x++] = a;
	return (1);
}

/**
 *_putsac - prints an input string
 * @str: the string to be printed
 * @ac: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsac(char *str, int ac)
{
	int x = 0;

	if (!str)
		return (0);
	while (*str)
	{
		x + = _putac(*str++, ac);
	}
	return (x);
}
