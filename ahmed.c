/* ahmed.c
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2022-10-13
 */

#include <stdio.h>

#define PI 3.1415

double calcArea( int radius);

int main(){

    // find the area of a circle with radius squared * PI

    int radius;

    printf("gimme a radius: ");
    scanf("%d", &radius);

    printf("ok %f \n", calcArea(radius));

    return 0;
}

double calcArea( int radius){

    double area;

    area = radius * radius;
    area = area * PI;

    return area;
}
