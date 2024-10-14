#include<stdio.h>

int main(int argc, char *argv[]){
    int x;
    int sum = 0;

    printf("Enter a number: ");
    scanf("%i", &x);

    for(int i=1;i<=x;i++){
        sum += i;
    }
    printf("The result is %d\n",sum);
}