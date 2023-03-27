#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include "token.h"

/*return execve first argument*/
char *search_path(char *p)
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
        sprintf(path_canditate, "%s%s%s", path_array[i], "/", p);
        if (access(path_canditate, F_OK) == 0)
        {
            return path_canditate;
        }
    }
}

void core_execute(char **command)
{
    if (fork() > 0)
    {
        wait(NULL);
    }
    else
    {
        if (execve(search_path(command[0]), command, NULL) == -1)
        {
            perror("command");
            exit(1);
        }
    }
}

void parser(token *p)
{
    int fd;
    int backupin = dup(0);
    int backupout = dup(1);
    int backuperr = dup(2);
    int flagin = 0;
    int flagout = 0;
    int flagerr = 0;
    char *command[100];
    memset(command, 0, 100);
    int i = 0;
    while (p != NULL)
    {

        switch (p->kind)
        {
        case TK_COMMAND:

            command[i] = p->str;
            i++;
            p = p->next;

            break;
        case TK_IN:
            if ((fd = open(p->next->str, O_RDONLY)) < 0)
            {
                perror("while opening file");
                exit(1);
            }
            dup2(fd, 0);
            close(fd);
            flagin++;
            p = p->next->next;
            break;
        case TK_OUT:
            if ((fd = open(p->next->str, O_CREAT | O_WRONLY, 0644)) < 0)
            {
                perror("while opening file open");
                exit(1);
            }
            dup2(fd, 1);
            close(fd);
            flagout++;
            p = p->next->next;
            break;
        case TK_ERR:
            if ((fd = open(p->next->str, O_CREAT | O_WRONLY, 0644)) < 0)
            {
                perror("while opening file open");
                exit(1);
            }
            dup2(fd, 2);
            close(fd);
            flagerr++;
            p = p->next->next;
            break;
        case TK_PIPE:
            int pipefds[2];
            pipe(pipefds);
            dup2(pipefds[1], 1);
            close(pipefds[1]);

            core_execute(command);

            i = 0;
            dup2(pipefds[0], 0);
            close(pipefds[0]);
            p = p->next;
            continue;
        default:
            puts("default");
        }
    }
    core_execute(command);
    if (flagin > 0)
    {
        dup2(backupin, 0);
        close(backupin);
    }
    if (flagout > 0)
    {
        dup2(backupin, 1);
        close(backupout);
    }
    if (flagerr > 0)
    {
        dup2(backuperr, 2);
        close(backuperr);
    }
}
