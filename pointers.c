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
#include <stdlib.h>

int main(){

    struct person {
        int age;
        char gender;
    };

/*     basic variables are created on the stack and the compiler 
    gives us a standardized notation so that we do not have
    to worry about indirection.  */

    int aNumber = 14;

/*     an exception is the array which uses indirection because
    of the overhead required to eliminate indirection, but it 
    does provide us with an alternative offset notation. */

    char aCString[] = "Hello World!";
    int * pointer2String;
    float aRealNumber = 4.12;

    int * arrayOfNumbers[3];

    struct person aPeople;

    struct person peoples[] = {{ 12, 'g' }, { 34, 'p' }, { 62, 'm'}, { 62, 'm'}, 
    { 62, 'm'}, { 8, 'm'}, { 9, 'm'}, { 10, 'm'}, { 48, 'm'}, { 62, 'm'} };

    struct person * harold = peoples;

    aPeople.age = 12;
    aPeople.gender = 'n';

/*     we can access their values like so */

    printf("%s and %d\n", aCString, aNumber);

/*     we can see their addresses like so */

    printf("%ld for the string and %ld for the integer.\n", 
        (long int) & aCString, (long int) & aNumber);

    printf("%d size of string %d size of int\n", (int)sizeof(aCString), (int)sizeof(aNumber));

    pointer2String = & aNumber;

    printf("%ld the pointer uninitialized is this.\n", (long int)pointer2String);

    printf("Harold is %d years old. The struct is %d bytes.\n", aPeople.age, (int)sizeof(aPeople) );

    printf("Float size: %d \n", (int)sizeof(aRealNumber));

    printf("second person age %d\n", peoples[1].age);

    printf("second person age from pointer %d\n", harold->age );

    (harold + sizeof(aPeople))->age = 50;

    printf("really the second person's age %d\n", ( harold + sizeof(aPeople))->age );
    
    arrayOfNumbers[0] = calloc(1, sizeof(int));

    * arrayOfNumbers[0] = 14;

    printf(" %d oh yeah...\n", * arrayOfNumbers[0]);

    free( arrayOfNumbers[0] );

    printf(" %d oh yeah...\n", * arrayOfNumbers[0]);

    return 14;
}


