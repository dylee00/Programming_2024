#include<stdio.h>

int main(int argc, char *argv[]){
    int x;
    printf("Enter an Integer: ");
    scanf("%i", &x);

    if(x < 0){
        x = -x;
    }
    
    printf("%d\n",x);
}
