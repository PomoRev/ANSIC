/* array_pointer.c
 * 
 * Playing with pointers and arrays
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2022-11-02
 */

#include <stdio.h>

int main(){

    /* using pointer with multidimensional arrays */

/*      1 2 3 4     (0,0) (0,1) (0,2) (0,3)
        1 2 4 5     (1,0) (1,2)
        3 3 4 2     (2,0)

        1 2 3 4 1 2 4 5 3 3 4 2
*/

    int array [3][4] = {{1,2,3,12},{1,2,4,5},{3,3,4,2}};
    /* int someNumber = 10; */
    int * pointer;
    int i;

/*  Strings are always terminated with a null (\0) character (so their
    size is one larger than the number of letters.) 
*/
    char string[] = "CST8117";  /* C S T 8 1 1 7 \0 */

    * (string + (sizeof(char) * 2)) = 'R';

    pointer = &array[0][1];

    printf ("the array has the value %d at coords 1,3.\n", pointer[7]);

    printf ("the course code is %s.\n", string );

    printf ("the third character is [%d].\n\n", string[2] ); 

    for (i=0; string[i] != '\0'; i++){

        printf("[%d]", (int)string[i]);

        if ( (string[i] >= 'A') && (string[i] <= 'Z') ){
            printf("found one.\n");
            string[i] += ('a'-'A');
        }
    }

    printf ("the course code is now %s.\n", string );

    return 0;

}


