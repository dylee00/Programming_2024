#include <stdio.h>

int main(void) {
    FILE *fp = NULL;
    char c;
    fp = fopen("sample_06.txt", "r");
    if(fp == NULL) {
        printf("파일을 못열음\n");
    }
    
    while((c = fgetc(fp)) != EOF) {
        putchar(c); 
    }
    
    fclose(fp);
}
