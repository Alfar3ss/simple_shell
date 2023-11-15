#include "shell.h"
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
 * checkmyownbuild - checks if the command is a buildin
 * @arv: array of words of the putted line
 * Return: p to the func that runs the buildin
 * */
void(*checkmyownbuild(char **arv))(char **arv)
{
	int i;
	ownbuild nour[] = {
		{"exit", sortu},{"setenv", _setenv},{"unsetenv", _unsetenv},{"env", env},{NULL, NULL}
	};
	for (i = 0; nour[i].name; i++)
	{
		if (_strcmp(arv[0], nour[i].name) == 0)
			return (nour[i].func);
	}
	/*return null*/
	return (NULL);
	
}

