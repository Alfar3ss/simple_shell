#include "shell.h"

/**
 * sig_handler - checks if Control+C is pressed
 * @sig_num: singal number 
 */
void sig_handler(int sig_num)
{
    if (sig_num == SIGINT)
    {
        _puts("\n#cIsNotFun$ ");
    }
}

/**
 * _EOF - handles the End of File
 * @len: return vlu of get line func
 * @buff: buffer
 */
void _EOF(int len, char *buff)
{
    /**loop*/
    (void)buff;
    if (len == -1)
    {
        if (isatty(STDIN_FILENO))
        {
            _puts("\n");
            free(buff);
        }
        exit(0);
    }
}

/**
 * _isatty - check if terminal
 */
void _isatty(void)
{
    if (isatty(STDIN_FILENO))
        _puts("#cIsNotFun$ ");
}

int main(void)
{
    ssize_t len = 0;
    char *buff = NULL, *value, *pathname, **arv;
    size_t size = 0;
    path_list *head = '\0';
    void (*f)(char **);

    signal(SIGINT, sig_handler);
    while (len != EOF)
    {
        /*isatty start here*/
        _isatty();
        len = getline(&buff, &size, stdin);
        _EOF(len, buff);
        arv = spiratstr(buff, " \n");  /*Corrected function name*/

        if (!arv || !arv[0])
            execute(arv);
        else
        {
            value = _getenv("PATH");
            head = linkpath(value);
            pathname = _which(arv[0], head);
            f = confirmbuild(arv);
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
    clean_list(head);
    my_free_arv(arv);
    free(buff);
    return (0);
}
