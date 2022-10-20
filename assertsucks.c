/* assertsucks.c
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2022-10-20
 */

#include <stdio.h>
#include <assert.h>

/* we did not use assert because it sucks, it is ok for 
sending stuff to stderr. big whoop. */

unsigned int checkForMod(unsigned int);

int main(){

    unsigned int returnedValue = checkForMod(117);

    if (checkForMod(25)) {

        printf ("(1)no change required.\n");

    } else {
        
        printf ("(0)cha-ching.\n");

    }

    if (returnedValue == 0) {

        printf ("(1)no change required.\n");

    } else {
        
        printf ("(0)cha-ching.\n");

    }

    return 0;
}

unsigned int checkForMod(unsigned int valueToTest){

    return ((valueToTest % 5) ? 0 : 1);

}


