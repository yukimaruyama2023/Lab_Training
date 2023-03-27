#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "token.h"

// store each token in a list of structure
token *tokenize(char *line)
{
    token *head, *current, *prev;
    head = (token *)malloc(sizeof(token));
    current = head;
    char *p = strtok(line, " ");
    current->str = p;
    current->kind = TK_COMMAND;
    current->next = NULL;

    while (1)
    {
        p = strtok(NULL, " ");
        if (p == NULL)
            break;
        prev = current;
        current = (token *)malloc(sizeof(token));
        prev->next = current;
        current->next = NULL;

        current->str = p;

        if (strncmp(p, ">", 1) == 0)
            current->kind = TK_OUT;
        else if (strncmp(p, "<", 1) == 0)
            current->kind = TK_IN;
        else if (strncmp(p, "2>", 2) == 0)
            current->kind = TK_ERR;
        else if (strncmp(p, "|", 1) == 0)
            current->kind = TK_PIPE;
        else
            current->kind = TK_COMMAND;
    }

    return head;
}