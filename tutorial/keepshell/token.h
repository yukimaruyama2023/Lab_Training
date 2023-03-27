typedef struct tmptoken
{
    char *str;
    struct tmptoken *next;
} token;

token *tokenize(char *);