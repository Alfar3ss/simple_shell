#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>

int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
char *_strdup(char *str);
char *link_all(char *name, char *sep, char *value);

char **spiratstr(char *str, const char *delim);
void execute(char **argv);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);


extern char **environ;

/**
 * struct path_list - Linked list containing PATH dirs
 * @dir: directory in path
 * @p: *p to next node
 */
typedef struct path_list
{
	char *dir;
	struct path_list *p;
} path_list;


char *_getenv(const char *name);
/*path list*/
path_list *add_node_end(path_list **head, char *str);
path_list *linkpath(char *path);
/*file name*/
char *_which(char *filename, path_list *head);

/**
 * minebuild is p of func
 ***********************
 *
 * @name: build-in 
 * *********************
 * 
 * @func: run  build-in 
 * 
 */
typedef struct minebuild
{
	char *name;
	void (*func)(char **);
} minebuild;

void(*confirmbuild(char **arv))(char **arv);
/*atoi*/
int my_atoi(char *s);
/*exit*/
void sortu(char **arv);
/*env*/
void theenv(char **arv);
/*set the env*/
void my_settheenv(char **arv);
/*unset the env*/
void my_unsettheenv(char **arv);

void my_free_arv(char **arv);
void clean_list(path_list *head);


#endif
