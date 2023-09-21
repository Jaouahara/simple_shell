#include "shell.h"

/**
 * _strdup - duplicate a string
 * @str: the inpute string
 * Return: pointer to a new alloc null-termi str or NULL on failure
 */
char *_strdup(const char *str)
{
	char *dup;
	int i;
	int len = 0;

	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		len++;
		str++;
	}
	str = str - len;
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
	for (i = 0; i <= len; i++)
		dup[i] = str[i];
	return (dup);
}

/**
 * _strlen - calculate the length of a null-terminated string
 * @s: the string hwo length to calcul
 * Return: length of string
 */
int _strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}

	return (length);
}

/**
 * _strcat - concatenate 2 null-terminated string
 * @dest: pointer to the destination string
 * @src: pointer to the source string
 * Return: pointer to the destination string
 */
char *_strcat(char *dest, char *src)
{
	char *temp = dest;

	while (*temp != '\0')
	{
		temp++;
	}
	while (*src != '\0')
	{
		*temp = *src;
		temp++;
		src++;
	}
	*temp = *src;
	return (dest);
}

/**
 * _strcpy - copy a null-terminated string to another null-terminated string
 * @dest: the destination null-terminated string
 * @src: the source null-terminated string
 * Return: pointer to the destinatoin string dest
 */
char *_strcpy(char *dest, char *src)
{
	char *temp = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return (temp);
}

/**
 * _strcmp - compare two null-terminated strings
 * @s1: pointer to the first null-terminated
 * @s2: pointer to the second null-terminated
 * Return: a pointer to an array of strings, or NULL on failure
 */
int _strcmp(char *s1, char *s2)
{
	int result = (int)*s1 - (int)*s2;

	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++, s2++;
		result = (int)*s1 - (int)*s2;
	}
	return (result);
}
