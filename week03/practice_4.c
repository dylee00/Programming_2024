#include <stdio.h>

int main(void) {

    float first_num;
    float second_num;
    float result;

    printf("enter two integers:");
    scanf("%f,%f",&first_num,&second_num);

    result = first_num/second_num;

    printf("%f / %f = %f\n",first_num,second_num,result);


    return 0;
}