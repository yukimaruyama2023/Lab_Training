
#include <stdio.h> 
#include <unistd.h> 
int main()
{
    fork();
    fork();
    printf("Hello\n");
    // exit(0);
    return 0;
}