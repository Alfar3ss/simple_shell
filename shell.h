#ifndef SHELL_H
#define SHELL_H
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




int nour_strlen(char *s);
char *concat_toutes(char *name, char *sep, char *value);
int nour_putchar(char c);
void nour_puts(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

char *_getenv(const char *name);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **diviserstr(char *str, const char *delim);
void execute(char **argv);
void _EOF(ssize_t len, char *buff);
void sig_handler(int sig);


extern char **environ;



/**
 * struct path_node - Linked list containing PATH directories
 * @dir: directory in path
 * @p: pointer to next node
 */
typedef struct path_node
/* Compare this snippet from shell.h: */
{
	char *dir;
	struct path_node *p;
} path_node;

path_node *add_node_end(path_node **head, char *str);
path_node *linkpath(char *path);
char *_which(char *filename, path_node *head);
void release_list(path_node *head);
char *_strdup(char *str);

/**
 * struct ownbuild - pointer to function with corresponding buildin command
 * @name: buildin command
 * @func: execute the buildin command
 */
typedef struct ownbuild

{
	char *name;
	void (*func)(char **);

} ownbuild;


void(*checkmyownbuild(char **arv))(char **arv);
void _setenv(char **arv);
void _unsetenv(char **arv);
void sortu(char **arv);
int _atoiAlfa(char *s);
void env(char **arv);
void freearv(char **arv);
int _strcmp(const char *s1, const char *s2);
#endif
