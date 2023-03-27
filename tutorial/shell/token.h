typedef enum
{
    TK_COMMAND,
    TK_IN,
    TK_OUT,
    TK_ERR,
    TK_PIPE,
} Tokenkind;

typedef struct tmptoken
{
    char *str;
    struct tmptoken *next;
    Tokenkind kind;
} token;

token *tokenize(char *);