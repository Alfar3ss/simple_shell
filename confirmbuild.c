#include "shell.h"

/**
 * confirmbuild - show if the command is a built-in command.
 * @arv: Array of arg.
 * Return: *p to a func that takes arv and returns void.
 */
void (*confirmbuild(char **arv))(char **)
{
    minebuild T[] = {
   	{"exit", sortu},
        {"setenv", my_settheenv},
        {"env", theenv},
        {"unsetenv", my_unsettheenv}
    };

    int i;
    /*looping starts*/
    for (i = 0; T[i].name; i++)
    {
        if (strcmp(T[i].name, arv[0]) == 0)
            return T[i].func;
    }
    /*returning*/
    return 0;
}
