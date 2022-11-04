/* passingarray.c
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2022-11-04
 */

#include <stdio.h>

int changeArray(char[]);

int main(){

    char arrayOne[4] = {'a','b','c','d'};

/*  the name of an array is an address to the first element
    it is the same as &array[0]. */

    changeArray( arrayOne );

    printf( "third character is %c\n", arrayOne[2]);

    return 0;
}

int changeArray(char * arrayInside){

    arrayInside[2] = 'p';

    printf( "inside I changed the third character to %c\n", arrayInside[2]);

    return 0;

}


