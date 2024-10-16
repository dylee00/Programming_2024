// #include <stdio.h>

// int main(void) {
//     int i;

//     for(int i=0;i<10;i++) {
//         printf("*");
//     }

//     for(int i=0;i<10;i++) {
//         printf("*");
//     }

//     for(int i=0;i<10;i++) {
//         printf("*");
//     }

//     return 0;
// }

#include <stdio.h>

void print_star()
{
    int i;
    for(int i=0;i<10;i++) {
        printf("*");
    }
}

int main(void) {
    int i;

   print_star();
   print_star();
   print_star();

    return 0;
}