#include<stdio.h>

int main(int argc, char *argv[]){
    int year,result1, result2,result3;
    printf("Input the year: ");
    scanf("%i",&year);
    //case -> result1 == 0 && result2 ==0 이거나 result3 == 0
    result1 = year%4; 
    result2 = year%100;
    result3 = year%400;

    printf("Is the year %d a leap year? %d\n", year, (result1 == 0 && result2 != 0) || result3 == 0);


}