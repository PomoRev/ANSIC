/* palindrome.c
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2022-09-30
 * 
 * takes a string from the user and tells us if it is
 * a palendrome (the same spelling backwards and
 * forwards).
 * 
 */

#include <stdio.h>

#define BOUNDS 14

int main(){

    char my_string[BOUNDS], letter = '\0', is_pal = 0;
    int offset = 0, tailset = 0;

    while ( (letter != '\n') && (offset < (BOUNDS - 1)) ){

        letter = my_string[offset++] = getchar();

    }

    my_string[offset] = '\0';

    offset = 0;

    /* check input for palindromeness */
    /* find the end */


    while ( my_string[tailset++] != '\0');
        tailset -= 3;

    /* compare end to front characters until they meet in middle */
    
    while ( offset < tailset ){

        if ( my_string[offset++] != my_string[tailset--]) 
            is_pal = 1;

    }

    /* if not compares fail it is a palindrome */

    if ( is_pal == 0 ) 
        printf ("=%s is a palindrome.", my_string);
    else 
        printf ("=%s is not a palindrome.", my_string); 


    return 0;

} 



