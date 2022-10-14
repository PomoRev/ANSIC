/* stackfun.c
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

    char * myarrays[4];
    char first[40] = "Hello";

    myarrays[0] = first;

    printf( "%s <---\n", myarrays[0] );

    screwuparray( myarrays );

    printf( "%s <--- in the main() at end\n", myarrays[0] );

    return 0;
}


void screwuparray( char ** myarray ){

    char literal[40] = "Goodbye";
    char string[40];
    char * allocatedmemory;

    printf( "%s --- %s \n", literal, myarray[0] );

    myarray[0] = "This one";

    printf( "%s --- %s \n", literal, myarray[0] );

    printf( "gimme a short string: ");
    scanf( "%s", string );

    myarray[0] = string;

    printf( "%s --- %s \n", literal, myarray[0] );

    addtostack();

    printf( "%s --- %s \n", literal, myarray[0] );

    allocatedmemory = addtoarray();

    printf( "%s heaping stuff\n", allocatedmemory );

    free( allocatedmemory );

    printf( "%s freed heaping stuff\n", allocatedmemory );

    return;

}

void addtostack(){

    char mymessagetotheworld[40] = "play more roleplaying games";

    printf( "Frank says to %s\n", mymessagetotheworld );

    return;

}

char * addtoarray(){

    char string[40] = "This is a message";
    int i;
    char * heapmemory;

    printf( "the string %s is %ld bytes\n", string, sizeof(string) );

    heapmemory = malloc( sizeof(string) );

/*     for(i=0;i<40;i++){
        heapmemory[i] = string[i];
    } */

    i = stringcopy( heapmemory, string );

    printf( "the string moved %s of %d bytes\n", 
        heapmemory, i );

    return heapmemory;
    
}

int stringcopy( char * target, char * original ){

/*     this copies an array of characters until it hit a NULL
    or it reaches the 39th character in the array. */

    int numcharacters = 0;

    while ( original[numcharacters] != '\0' && numcharacters < 39 ){

        target[numcharacters] = original[numcharacters];
        numcharacters++;

    }

    target[numcharacters] = '\0';

    return numcharacters;

}
