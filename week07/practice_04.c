#include <stdio.h>



//n!
int factorial(int num){
    int res = 1;
    for(int i=1;i<=num;i++){
        res *= i;
    }
    return res;
}

//(n-r)!
int combination(int num1, int num2){
    int result;
    result = factorial(num1 - num2);
    return result;
}

//값 입력
int get_integer(){
    int num;

    printf("Enter the value: ");
    scanf("%d", &num);

    return num;
}

int main(void) {
    int num1, num2;
    int numerator, denominator;
    int result;


    num1 = get_integer();
    num2 = get_integer();

    //분자 n! 분모 (n-r)!r!
    numerator = factorial(num1);
    denominator = (combination(num1,num2)*factorial(num2));

    result = numerator / denominator;

    printf("The result of C(%d,%d)is %d.\n", num1,num2,result);
    return 0;
}