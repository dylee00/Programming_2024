#include<stdio.h>

struct point {
    int x;
    int y;
};
int getArea(struct point p1, struct point p2) {
    int area;

    printf("Input p1 coordinate (x,y): ");
    scanf("%d %d" ,&p1.x, &p1.y); 
    printf("Input p2 coordinate (x,y): ");
    scanf("%d %d" ,&p2.x, &p2.y);

    area =(p2.x - p1.x) *(p2.y - p1.y);

    return area;
};

int main(void) {
    struct point p1,p2;

    int area = getArea(p1,p2);

    printf("Area: %d\n", area);
   
}