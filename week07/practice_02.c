#include<stdio.h>
int sumTwo(int a, int b){
    return a + b;
}

int square(int n){
    return n*n;
}

int get_max(int x, int y){
    if(x > y){
        return x;
    } else {
        return y;
    }
}

int main(void) {
    int a, b;
    printf("Enter the integers: ");
    scanf("%d %d", &a, &b);
    printf("Result - Sum: %d, Square: %d, Max: %d \n", sumTwo(a, b),square(a), get_max(a, b));


    return 0;
}