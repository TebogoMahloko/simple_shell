#include "shell.h"

/**
 * _strlen - Return the length of a string
 * @s: The string whose length to check
 *
 * Return: The integer length of the string
 */
int _strlen(char *s)
{
	int length = 0;

	if (!s)
		return (0);

	while (*s)
	{
		length++;
		s++;
	}

	return (length);
}
/**
 * _strcmp - Compare two strings
 * @s1: The first string
 * @s2: The second string
 * Return: An integer less than,equal to,or geater than zero if s1 is found to
 * be less than,equal to,or greater than s2,respectively.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return ((*s1 < *s2) ? -1 : 1);
}
/**
 * starts_with - Check if a string starts with another string
 * @haystack: The string to search in
 * @needle: The string to search for
 *
 * Return: A pointer to the location in haystack where needle starts,
 * or NULL if needle is not found.
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
	{
		if (*needle++ != *haystack++)
		{
			return (NULL);
		}
	}
	return ((char *)haystack);
}
/**
 * _strcat - Concatenate two strings
 * @dest: The destination string
 * @src: The source string
 * Return: A pointer to the concatenated string
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (ret);
}
