#include <stdio.h>
#include <stdint.h>

/*change show()*/
// struct ColoredPoint {
//     int x;
//     int y;
//     int color; 
// };

// struct Point {
//     int x;
//     int y;

// };
// void show(struct Point *p){
//     int x = *(int *)p;
//     int y = *(int *)(p + 4);
//     int color = *(int *)(p + 8);
//     printf("(%d, %d) color is %d\n", x, y, color);
// }
// int main(){
//     struct ColoredPoint c = {3, 4, 5};
//     show(&c);

//     return 0;
// }

struct ColoredPoint {
    int x;
    int y;
    int color; 
};

struct Point {
    int x;
    int y;
};
void show(struct Point *p){
    printf("(%d, %d)\n", p->x, p->y);
}
int main(){
    struct ColoredPoint c = {3, 4, 5};
    /*indicate y and color*/
    // int *q = (int *)(&c) + 1;
    // struct Point *u = (struct Point *)(q);
    // show(u);

    /*indicate x and y*/
    struct Point *u = (struct Point *)(&c);
    show(u);

    return 0;
}

