/* filename.c
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2022-11-18
 */

#include <stdio.h>
#define SIZE 14

void initializearray( char array[] ){

    int i;

    for (i = 0; i < SIZE; i++) array[i] = 'C';

}

void printarray(char array[]){

    int i;

    for (i = 0; i < SIZE; i++) printf("%c ", array[i]);

    printf("\n");

}

int main(){

    char array[SIZE];

    initializearray(array);

    printarray(array);

    return 0;
}


