#include<stdio.h>

int main(int argc, char *argv[]){
    int answer = 50;
    int result;
    int score = 0;

    do {
        printf("Guess a number: ");
        scanf("%d", &result);

        score++;  // 시도 횟수를 증가시킴

        // 사용자의 입력이 정답보다 큰지 작은지 판단
        if(result > answer) {
            printf("High!\n");
        } else if(result < answer) {
            printf("Low!\n");
        } else {
            printf("Congratulations! Trials: %d\n",score);
        }
    } while(result != answer);  // 정답이 아니면 반복

}