#include <stdio.h>

int main(){

    int number = 0;

    for (; number < 25; number++){

        printf("line %d ", number);


        if ( (number%7) == 0 ){

            printf( "is a multiple of 7");
        }

        printf("\n");

    }

    return 0;
}