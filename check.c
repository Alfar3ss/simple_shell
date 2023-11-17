#include "shell.h"

/**
 * checkmyownbuild - checks if the command is a buildin
 * @arv: array of words of the putted line
 * Return: p to the func that runs the buildin
 * */

void(*checkmyownbuild(char **arv))(char **arv)
{
	int i;
	ownbuild nour[] = {
		{"exit", sortu},
		{"env", env},
		{"unsetenv", _unsetenv},
		{"setenv", _setenv},		
		{NULL, NULL}
	};
	for (i = 0; nour[i].name; i++)
	{
		if (_strcmp(arv[0], nour[i].name) == 0)
			return (nour[i].func);
	}
	return (NULL);
	
}
