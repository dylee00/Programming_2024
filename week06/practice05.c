#include<stdio.h>

int main(int argc, char *argv[]){
    int x,y;
    char operator;
    int result;
    printf("Enter the calculation: ");
    scanf("%i", &x);
    scanf(" %c", &operator);
    scanf("%i", &y);
    switch (operator)
    {
    case '+':
        result = x + y;
        break;
    
    case '-':
        result = x - y;
        break;

    case '/':
         if (y == 0) {
            printf("Error: Division by zero is not allowed.\n");
        }
        result = x / y;
        break;

    case '*':
        result = x * y;
        break;

    default:
        break;
    }
    printf("= %d\n", result);
}