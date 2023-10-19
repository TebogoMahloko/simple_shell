#include "shell.h"

/**
 * _strcpy - Copy a string
 * @dest: The destination
 * @src: The source
 *
 * Return: A pointer to the destination
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == NULL)
		return (dest);

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}

/**
 * _strdup - Duplicate a string in memory
 * @str: The string to duplicate
 *
 * Return: A pointer to the newly allocated string, or NULL if allocation fails
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;
	int i;

	if (str == NULL)
		return (NULL);

	while (str[length])
		length++;

	ret = (char *)malloc(sizeof(char) * (length + 1));

	if (ret == NULL)
		return (NULL);

	for (i = 0; i <= length; i++)
		ret[i] = str[i];

	return (ret);
}

/**
 * _puts - Print a string to stdout
 * @str: The string to print
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - Emulate _putchar and write to the buffer
 * @c: The character to write
 *
 * Return: 1 on success, -1 on failure
 */
int _putchar(char c)
{
	static int index;
	static char buffer[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || index >= WRITE_BUF_SIZE)
	{
		write(1, buffer, index);
		index = 0;
	}
	if (c != BUF_FLUSH)
		buffer[index++] = c;
	return (1);
}

