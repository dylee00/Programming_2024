#include<stdio.h>

int main(int argc, char *argv[]){
    int x;
    printf("Enter an Integer: ");
    scanf("%i", &x);

    if(x == 0){
        printf("This is 0\n");
    } else if(x > 0){
        printf("This is a positive number\n");
    } else if(x < 0){
        printf("This is a negative odd number\n");
    }
}
