#include<stdio.h>

struct student
{
    int ID;
    int score;
};

int main(void) {

    struct student s[4];
    float avg = 0;
    int max_id = 0;
    int max_score = 0;

    for(int i=0;i<4;i++){
        printf("Input the ID: ");
        scanf("%d",&s[i].ID);
        printf("Input the score: ");
        scanf("%d",&s[i].score);
    }

    for(int i=0;i<4;i++){
        avg += s[i].score;
        if(s[i].score > max_score){
            max_score = s[i].score;
            max_id = s[i].ID;
        }
    }
    avg /= 4;

    printf("The average of the score: %f\n",avg);
    printf("The highest score - ID: %d, score: %d\n",max_id,max_score);
}
