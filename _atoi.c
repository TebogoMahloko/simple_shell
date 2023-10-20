#include "shell.h"

/**
 * interactive - returns true if the shell is in interactive mode
 * @info: structure address
 *
 * Return: 1 when in interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - Checks if a character is in a set of delimiters.
 * @c: The character to check.
 * @delim: A string containing delimiters.
 *
 * Return: 1 if the character is a delimiter, 0 otherwise.
 */
int is_delim(char c, char *delim)
{
	for (; *delim; delim++)
	{
		if (*delim == c)
			return (1);
	}
	return (0);
}

/**
 * _isalpha - Checks if a character is an alphabetic character.
 * @c: The character to check.
 *
 * Return: 1 if the character is alphabetic, 0 otherwise.
 */
int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ? 1 : 0);
}

/**
 * _atoi - Converts a string to an integer
 * @s: The string to convert
 *
 * Return: The integer converted from the string
 */
int _atoi(char *s)
{
	int i, sign = 1, flag = 0;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		return (-result);
	else
		return (result);
}
