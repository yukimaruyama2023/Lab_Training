#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main()
{
    printf("%ld\n", sizeof(uint64_t));
    printf("%ld\n", sizeof(uint8_t));
    printf("%ld\n", sizeof(uint8_t *));
    printf("%ld\n", sizeof(char *));
    printf("%ld\n", sizeof(int *));
    printf("%ld\n", sizeof(float *));
}