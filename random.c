/* random.c
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2022-11-04
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    /* create a seed for our sequence of random numbers */

    time_t currentTime;
    int i;

    currentTime = time(NULL);

    srand(currentTime);


    for (i=0; i< 12; i++){

        printf("Number %d: %d\n", i, (rand() % 15) + 1 );

    }

    return 0;
}



