/* pointers.c
 *
 * This code is created for an explanatory session with
 * a student to provide a good working example of dynamic
 * memory use and basic indirection in C programming.
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2022-10-19
 */

#include <stdio.h>

int main(){

/*     basic variables are created on the stack and the compiler 
    gives us a standardized notation so that we do not have
    to worry about indirection.  */

    int aNumber = 14;

/*     an exception is the array which uses indirection because
    of the overhead required to eliminate indirection, but it 
    does provide us with an alternative offset notation. */

    char aCString[] = "Hello World!";

/*     we can access their values like so */

    printf("%s and %d\n", aCString, aNumber);

/*     we can see their addresses like so */

    printf("%ld for the string and %ld for the integer.\n", 
        (long int)&aCString, (long int)&aNumber);

    return 0;
}


