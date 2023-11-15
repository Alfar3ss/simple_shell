#include "shell.h"

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: 0 if equal, negative if s1 < s2, positive if s1 > s2
 */
char *_strdup(char *str)
{
	int i, l;
	char *new;

	if (!str)
	{
		return (NULL);
	}
	for (l = 0; str[l] != '\0';)
	{
		l++;
	}
	new = malloc(sizeof(char) * l + 1);
	if (!new)
	{
		return (NULL);
	}
	for (i = 0; i < l; i++)
	{
		new[i] = str[i];
	}
	new[l] = str[l];
	return (new);
}

/**
 * concat_toutes - concats 3 strings in a newly allocated memory
 * @name: first string
 * @sep: second string
 * @value: Third string
 * Return: pointer to the new string
 */
char *concat_toutes(char *name, char *sep, char *value)
{
	char *resultat;
	int len1, len2, len3, i, k;

	len1 = nour_strlen(name);
	len2 = nour_strlen(sep);
	len3 = nour_strlen(value);

	resultat = malloc(len1 + len2 + len3 + 1);
	if (!resultat)
		return (NULL);

	for (i = 0; name[i]; i++)
		resultat[i] = name[i];
	k = i;

	for (i = 0; sep[i]; i++)
		resultat[k + i] = sep[i];
	k = k + i;

	for (i = 0; value[i]; i++)
		resultat[k + i] = value[i];
	k = k + i;

	resultat[k] = '\0';

	return (resultat);
}

/**
 * nour_strlen -  length of a string
 * @s: ptr to the str
 * Return: len to str
 */
int nour_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/*
* nour_putchar - outputs a char
* @c: char to be outputed
* Return: 1
*/
int nour_putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * nour_puts - outmuts a str
 * @str: ptr to the str
 */

void nour_puts(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		nour_putchar(str[i]);
		i++;
	}
}
