#include <stdio.h>

int main(void) {
    int i;
    int grade[5];

    //숫자 저장
    for(i=0;i<5;i++){
        printf("Input value-grade[%i]=",i);
        scanf("%d",&grade[i]);
    }

    int average = 0;
    int *ptr = grade;
    //포인터 변수로 grade 배열에 접근
    //int 배열 -> 4 byte
    for(i=0;i<5;i++){
        int *ptr = grade;
        printf("grade[%i]=%i\n",i,*(ptr + i));
        average += *(ptr+i);
    }

    printf("average: %i\n",average/5);

    return 0;
}

