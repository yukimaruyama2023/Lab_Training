#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"
#include "parser.h"

extern void excute();
extern token *tokenize(char *);

int main()
{
    char line[256];

    for (;;)
    {

        printf("$ ");
        fgets(line, sizeof(line), stdin);
        line[strlen(line) - 1] = '\0';
        token *com = tokenize(line);
        if (strcmp(line, "exit") == 0)
        {
            exit(0);
        }

        excute(com);
    }

    return 0;
}