/*
 * num2octstars.c
 *
 * Frank Emanuel
 * emanuef@algonquincollege.com
 * 
 * reads in a whole number and prints it
 * out as groups of 8 stars, including
 * the remaining stars at the bottom.
 */

#include <stdio.h>
 
int main(){

    int number = 0, i;

// get a whole number

    printf("gimme a positive whole number greater than 0: ");
    scanf("%d", &number);

// divide number by 8
// loop once for each multiple of 8 

for( i = 0; i < (number / 8); i++ ){
    // print a row of 8 stars
    printf("* * * * * * * *\n");
}

// mod the number by 8
for( i = 0; i < (number % 8); i++){
//     print one star for each remaining value
    printf("* ");
}

// print a newline

    if ((number % 8) > 0) printf("\n");

    return 0;
}
