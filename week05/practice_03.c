#include<stdio.h>

int main(int argc, char *argv[]){
    int param,hour,minute;
    printf("Input the second: ");
    scanf("%i",&param);
    hour = param/60;
    minute = param%60;
    printf("the time is %d:%d\n",hour,minute);

}