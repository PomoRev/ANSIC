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

    char my_string[BOUNDS], letter = '\0', is_palindrome = 0;
    int offset = 0, tailset = 0;

    /* use getchar() to safely populate our string to check, terminating the
     * string with a NULL ('\0') character. 
     */

    while ( (letter != '\n') && (offset < (BOUNDS - 1)) ){

        letter = my_string[offset++] = getchar();

    }
    my_string[offset] = '\0';

    /* reset the offset to the front of the string 
     */

    offset = 0;

    /* find the end of the string and ensure tailset points to the last character
     * before the terminating NULL.
     */

    while ( my_string[tailset++] != '\0');
    tailset -= 3;

    /* compare end to front characters moving the offsets until they meet in middle 
     */
    
    while ( offset < tailset ){

        if ( my_string[offset++] != my_string[tailset--]) 
            is_palindrome = 1;

    }

    /* if no compares fail then it is a palindrome, print result
     */

    if ( is_palindrome == 0 ) 
        printf ("=%s is a palindrome.", my_string);
    else 
        printf ("=%s is not a palindrome.", my_string); 


    return 0;

} 



