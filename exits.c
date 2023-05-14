#include "shell.h"

/**
 *_strncpy - copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@a: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int x, y;
	char *z = dest;

	x = 0;
	while (src[x] != '\0' && x < a - 1)
	{
		dest[x] = src[x];
		x++;
	}
	if (x < a)
	{
		y = x;
		while (y < a)
		{
			dest[y] = '\0';
			y++;
		}
	}
	return (z);
}

/**
 *_strncat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@a: the amount of bytes to be used to maximum
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int a)
{
	int x, y;
	char *z = dest;

	x = 0;
	y = 0;
	while (dest[x] != '\0')
		x++;
	while (src[y] != '\0' && y < a)
	{
		dest[x] = src[y];
		x++;
		y++;
	}
	if (y < a)
		dest[x] = '\0';
	return (z);
}

/**
 *_strchr - locates a character in a string
 *@z: the string to be parsed
 *@t: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *z, char t)
{
	do {
		if (*z == t)
			return (z);
	} while (*z++ != '\0');

	return (NULL);
}
