#include<stdio.h>

struct student
{
    int ID;
    char name[10];
    double grade;
};

int main(void) {
    struct student *strPtr;
    struct student s = {2110072, "LEE",4.3};
    strPtr = &s;

    printf("ID: %d\n",strPtr->ID);
    printf("name: %s\n",strPtr->name);
    printf("grade: %f\n",strPtr->grade);
}
