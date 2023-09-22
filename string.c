#include "shell.h"
/**
 * _strdup - a function
 * @str: a double pointer
 * Return: a pointer
 */
char *_strdup(const char *str)
{
	char *ptr;
	int i, len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len])
		len++;

	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		ptr[i] = str[i];
	return (ptr);
}
/**
 * _strcmp - a function
 * @s1: a  pointer
 * @s2: a pointer
 * Return: a pointer
 */
int _strcmp(char *s1, char *s2)
{
	int cmp;

	cmp = (int)*s1 - (int)*s2;
	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
		cmp = (int)*s1 - (int)*s2;
	}
	return (cmp);
}
/**
 * _strlen - a function
 * @s: a  pointer
 * Return: integer
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}
/**
 * _strcat - a function
 * @dest: a  pointer
 * @src: a pointer
 * Return: a pointer
 */
char *_strcat(char *dest, char *src)
{
	char *p = dest;

	while (*p)
		p++;

	while (*src)
	{
		*p = *src;
		p++;
		src++;
	}
	*p = '\0';
	return (dest);
}
/**
 * _strcpy - a function
 * @dest: a  pointer
 * @src: a pointer
 * Return: a pointer
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
