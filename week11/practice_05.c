#include <stdio.h>

int main(void) {
    FILE *fp;
    fp = fopen("sample.txt", "w");

    for (int i = 0; i < 3; i++) {
        char str[100];  
        printf("Input a word: ");
        scanf("%s", str);  

        fprintf(fp, "%s\n", str);  
    }

    fclose(fp);

}