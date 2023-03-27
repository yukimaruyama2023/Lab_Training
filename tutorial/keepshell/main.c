#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include "token.h"

extern void excute();
extern token *tokenize(char *);

// void handler(int sig)
// {
//     char *msg = "You can't stop me by Ctrl-C!\n";
//     write(1, msg, strlen(msg));
// }

int main()
{
    char line[256];

    // struct sigaction act;
    // memset(&act, 0, sizeof(act));
    // act.sa_handler = handler;
    // sigaction(SIGINT, &act, NULL);

    for (;;)
    {

        printf("$ ");
        fgets(line, sizeof(line), stdin);
        line[strlen(line) - 1] = '\0';
        token *com = tokenize(line);
        if (strcmp(com->str, "exit") == 0)
        {
            exit(0);
        }
        else if (strcmp(com->str, "cd") == 0)
        {

            if ((com->next->str) == NULL)
            {
                chdir(getenv("HOME"));
            }
            else
            {
                if ((chdir(com->next->str)) == -1)
                {
                    printf("cd: no such directory: %s\n", com->next->str);
                }
            }
        }
        else
        {
            excute(com);
        }
    }

    return 0;
}