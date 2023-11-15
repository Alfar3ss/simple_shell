#include "shell.h"

/**
 * sortu - exit the shell with or without a return of status n
 * @arv: array of words of the inputted line
 */
void sortu(char **arv)
{
	int i, j;

	if (!arv[1])
	{exit(0);}
	else
	{i = _atoiAlfa(arv[1]);
		if (i < 0)
		{perror(_getenv("_"));
			return;
		}
		else
		{
			j = i;
			exit(j);
		}
	}
}
