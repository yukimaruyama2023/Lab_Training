#include <stdio.h>
char x; int y;
int main() {
    printf("x:␣%p\n", &x); // 変数 x の割り当てられているアドレスを表示する 
    printf("y:␣%p\n", &y); // 変数 y の割り当てられているアドレスを表示する
    return 0;
}