#include <stdio.h>
#include <stdalign.h>

int main() 
{
    printf("Size of int:%zu\n", alignof(int));
    printf("Size of long:%zu\n", alignof(long));
    printf("Size of long long:%zu\n", alignof(long long));
    printf("Size of float:%zu\n", alignof(float));
    printf("Size of double:%zu\n", alignof(double));

    printf("Alignment of int:%zu\n", alignof(int));
    printf("Alignment of long:%zu\n", alignof(long));
    printf("Alignment of long long:%zu\n", alignof(long long));
    printf("Alignment of float:%zu\n", alignof(float));
    printf("Alignment of double:%zu\n", alignof(double));

    return 0;
}