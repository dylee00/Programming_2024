#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int main(void) {
    int i;
    int grade[SIZE];
    int score[SIZE];

    for(i=0;i<SIZE;i++) {
        grade[i] = rand()%100;
        score[i] = grade[i];
        printf("grade[%d] = %d\n",i,grade[i]);
    }

    printf("\n");

    for(i=0;i<SIZE;i++) {
        printf("score[%d] = %d\n",i,score[i]);
    }

    return 0;
}