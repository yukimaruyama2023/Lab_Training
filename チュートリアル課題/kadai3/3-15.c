#include <stdio.h>
#include <stdint.h>

extern struct X caller_struct();

struct X {
    int64_t x;
    int64_t y;
};

void callee_struct(struct X s)
{
    puts("callee_struct:");
    printf("\t.x = % ld\n", s.x);
    printf("\t.y = % ld\n", s.y);
}

struct X callee_ret_struct()
{
    struct X s = {
        .x = 123,
        .y = 456,
    };
    puts("callee_ret_struct:");
    printf("\t.x = %ld\n", s.x); 
    printf("\t.y = %ld\n", s.y); 

    return s;
}

int main(){
    caller_struct();
    return 0;
}

// /*not use assenbly file*/
// struct X {
//     int64_t x;
//     int64_t y;
// };

// void callee_struct(struct X s)
// {
//     puts("callee_struct:");
//     printf("\t.x = % ld\n", s.x);
//     printf("\t.y = % ld\n", s.y);
// }

// struct X callee_ret_struct()
// {
//     struct X s = {
//         .x = 123,
//         .y = 456,
//     };
//     puts("callee_ret_struct:");
//     printf("\t.x = %ld\n", s.x); 
//     printf("\t.y = %ld\n", s.y); 

//     return s;
// }
// void caller_struct(){
//     struct X t = callee_ret_struct();
//     t.x += 200;
//     t.y += 200;
//     callee_struct(t);
// }

// int main(){
//     caller_struct();
//     return 0;
// }