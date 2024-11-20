#include <stdio.h>

//포인터 자료형에 따라 그 크기로 값을 읽어옴
int main(void) {
    int i = 300;

    int *pi = &i;
    char *pc = &i;

    printf("%i, %i, %i\n",i,*pi,*pc);    
}
