/* stackfun.c
 * 
 * This file was made in lab 6 as a way of showing how to 
 * use memory allocation, but also how to safely work with 
 * data on the stack from a called environment. 
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2022-10-14
 */

#include <stdio.h>
#include <stdlib.h>

void screwuparray( char ** );
void addtostack();
char * addtoarray();
int stringcopy( char *, char * );

int main(){

    /* set up some data to work with */

    char * myarrays[4];
    char first[40] = "Hello";

    /* point to the first string */

    myarrays[0] = first;

    /* confirm that our array is set up as expected */

    printf( "%s <---\n", myarrays[0] );

    /* create a new environment on the stack to work with our array (takes a pointer) */

    screwuparray( myarrays );

    /* see what it is like coming back to the main() this is not reliable 
       because it is using memory from the stack which we have messed with
       but it might work (it did in class and does on my window's 
       computer) */

    printf( "%s <--- in the main() at end\n", myarrays[0] );

    return 0;
}


void screwuparray( char ** myarray ){

    /* allocate some memory on the stack */

    char literal[40] = "Goodbye";
    char string[40];
    char * allocatedmemory;

    /* check my literal and that I can see the value in the passed array */

    printf( "%s --- %s \n", literal, myarray[0] );

    /* put the string literal in the array (overwriting the first element) */

    myarray[0] = "This one";
    printf( "%s --- %s \n", literal, myarray[0] );

    /* prompt for a string from the user and then 
       put this into the array's first element */

    printf( "gimme a short string: ");
    scanf( "%s", string );

    myarray[0] = string;
    printf( "%s --- %s \n", literal, myarray[0] );

    /*  this was an experiment to add data onto the stack, but it should have
        been called in main to overwrite the memory, which is likely why it seemed
        to not mess up our previous stack memory. even though the stack pointer 
        moved we did not ever call a part of the stack that was re-allocated. */

    addtostack();
    printf( "%s --- %s \n", literal, myarray[0] );

    /* dynamically create a string on the heap and return the address of this string. */

    allocatedmemory = addtoarray();
    printf( "%s heaping stuff\n", allocatedmemory );

    /*  always keep track of any heap allocations so that you can release the memory, this 
        prevents a memory leak. Note that if you end main() the operating system will 
        deallocate all of the memory from the program, but only when the program terminates.
        Because your program could crash, you should always safely manage your memory. */ 

    free( allocatedmemory );
 
    /*  this should show that the pointer now points to somewhere random, in our running in
        class it pointed to several single characters which are likely just artifacts in memory.
        you should not do this because you could end up going outside of memory bounds and it 
        will result in a segmentation fault (when you try to access memory that was not allocated
        to your program by the operating system.) */
 
    printf( "%s freed heaping stuff\n", allocatedmemory );

    return;

}

void addtostack(){

    /*  This was simply putting a called environment on the stack to see how that effected
        the variables we were working with. */

    char mymessagetotheworld[40] = "play more roleplaying games";
    printf( "Frank says to %s\n", mymessagetotheworld );

    return;

}

char * addtoarray(){

    /*  allocates enough memory to hold our 40 byte array on the heap, then copies
        the string literal into the newly allocated memory returning a pointer to 
        this memory (now holding our string) */

    char string[40] = "This is a message";
    int i;
    char * heapmemory;

    /*  this line was just confirming the size, in bytes, of our string. we need the size to 
        know what to allocate. Note that we allocate the largest possible size, not just how
        much of that array we are using for our string. */

    printf( "the string %s is %ld bytes\n", string, (long)sizeof(string) );

    heapmemory = malloc( sizeof(string) );

    /*  the commented code is how we initially moved things over - note byte by byte */

/*     for(i=0;i<40;i++){
        heapmemory[i] = string[i];
    } */

    /*  at this point we used a stringcopy function we quickly created to only copy over
        the part of the array we actually use for our string. This could be modified to 
        make a useful array copy mechanism. */ 

    i = stringcopy( heapmemory, string );

    printf( "the string moved %s of %d bytes\n", heapmemory, i );

    /* return the pointer to the calling environment */

    return heapmemory;
    
}

int stringcopy( char * target, char * original ){

    /*  this copies an array of characters until it hit a NULL
        or it reaches the 39th character in the array. 
        To make this useful consider having it do bounds checking another
        way, perhaps with a value sent in or with a stated requirement that 
        the target string have enough allocated space to hold the original
        string. The return value is the count of bytes copied.    
    */

    int numcharacters = 0;

    while ( original[numcharacters] != '\0' && numcharacters < 39 ){

        target[numcharacters] = original[numcharacters];
        numcharacters++;

    }

    /* strings are simply character arrays terminated by a NULL ('\0') character */

    target[numcharacters] = '\0';

    return numcharacters;

}
