#include "shell.h"

/**
 * sig_handler - checks if Ctrl C is pressed
 * @sig_num: int
 */
void sig_handler(int sig_num)
{
	if (sig_num == SIGINT)
	{
		nour_puts("\n#ModeTunedOn$ ");
	}
}

/**
* _EOF - checks if EOF is pressed
* @len: length
* @buff: buffer
 */
void _EOF(int len, char *buff)
{
	(void)buff;
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			nour_puts("\n");
			free(buff);
		}
		exit(0);
	}
}
/**
  * _isatty - checks if the shell is interactive
  */

void _isatty(void)
{
	if (isatty(STDIN_FILENO))
	{
		nour_puts("#ModeTunedOn$ ");
	}
}
/**
 * main - main function
 * Return: 0
 */

int main(void)
{
	ssize_t len = 0;
	char *buff = NULL, *value, *pathname, **arv;
	size_t size = 0;
	path_node *head = '\0';
	void (*f)(char **);

	signal(SIGINT, sig_handler);
	while (len != EOF)
	{
		_isatty();
		len = getline(&buff, &size, stdin);
		_EOF(len, buff);
		arv = diviserstr(buff, " \n");
		if (!arv || !arv[0])
			execute(arv);
		else
		{
			value = _getenv("PATH");
			head = linkpath(value);
			pathname = _which(arv[0], head);
			f = checkmyownbuild(arv);
			if (f)
			{
				free(buff);
				f(arv);
			}
			else if (!pathname)
				execute(arv);
			else if (pathname)
			{
				free(arv[0]);
				arv[0] = pathname;
				execute(arv);
			}
		}
	}
	release_list(head);
	freearv(arv);
	free(buff);
	return (0);
}
