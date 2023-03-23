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
    while (p != NULL)
    {
        prev = current;
        current = (token *)malloc(sizeof(token));
        prev->next = current;
        p = strtok(NULL, " ");
        current->str = p;
    }

    // // debag
    // token *q = head;
    // while (q != NULL)
    // {
    //     printf("%s\n", q->str);
    //     q = q->next;
    // }
    return head;
}