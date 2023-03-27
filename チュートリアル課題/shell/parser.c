#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include "token.h"

/*return execve first argument*/
char *search_path(token *p)
{
    char *pathvar;
    char *path_array[10];

    if ((pathvar = getenv("PATH")) == NULL)
    {
        printf("pathvar is NULL\n");
    }

    char *u = strtok(pathvar, ":");
    path_array[0] = u;
    for (int i = 1; i < 10; i++)
    {

        if ((u = strtok(NULL, ":")) == NULL)
            break;
        path_array[i] = u;
        static char path_canditate[100];
        sprintf(path_canditate, "%s%s%s", path_array[i], "/", p->str);
        if (access(path_canditate, F_OK) == 0)
        {
            return path_canditate;
        }
    }
}

void excute(token *p)
{
    if (fork() > 0)
    {
        wait(NULL);
    }
    else
    {
        char *args[10];

        // fill the array with null character
        memset(args, 0, 10);

        token *q = p;
        for (int i = 0; q != NULL && i < 10; q = q->next, i++)
        {
            args[i] = q->str;
        }
        if (execve(search_path(p), args, NULL) == -1)
        {
            perror("command");
            exit(1);
        }
    }
}
