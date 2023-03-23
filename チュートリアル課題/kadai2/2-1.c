#include <stdio.h> 
double w;
double x;
float y;
float z;

int main() {
    printf("w:␣%p\n", &w); // 変数 w の割り当てられているアドレスを表示する
    printf("x:␣%p\n", &x); // 変数 x の割り当てられているアドレスを表示する
    printf("y:␣%p\n", &y); // 変数 y の割り当てられているアドレスを表示する
    printf("z:␣%p\n", &z); // 変数 z の割り当てられているアドレスを表示する
    return 0;
}
