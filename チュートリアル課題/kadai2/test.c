#include <stdio.h> 
int main() {
    char x = 'a';
    char *xp;
    int y = 123;
    
    int *yp; 
    xp = &x; // char 型へのポインタに char 型の変数のアドレスを入れる
    yp = &y; // int 型へのポインタに int 型の変数のアドレスを入れる
    // 変数 xp にはアドレスが入っている.
    // そのアドレスに char 型の値が格納されている.
    // *xp によりその値 (char 型) を取り出して表示.
    printf("&x␣=␣%p\n", &x); // 変数 x が置かれているアドレスを表示
    printf("xp␣=␣%p\n", xp); // xp の値は変数 x の置かれているアドレスに一致する
    printf("x␣=␣%c\n", *xp); // a が表示される
    // 変数 yp にはアドレスが入っている.
    // そのアドレスから始まる 4 バイトに int 型の値が格納されている.
    // *yp によりその値 (int 型) を取り出して表示.
    printf("&y␣=␣%p\n", &y); // 変数 y が置かれているアドレスを表示
    printf("yp␣=␣%p\n", yp); // yp の値は変数 y の置かれているアドレスに一致する
    printf("y␣=␣%d\n", *yp); // 123 が表示される
    return 0;
}