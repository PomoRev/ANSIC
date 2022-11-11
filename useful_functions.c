/* useful.c
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2022-09-30
 * 
 * Library of functions for use in projects, including test code (main())
 * Expect this file to grow as we learn together.
 * 
 */

#include <termios.h>
#include <unistd.h>
#include <stdio.h>

#define STRINGSIZE 32

int get_string( int bounds, char * string );
int get_length( const char * string );
int getch(void);
/* int getachar( void ); */

int main(){

    char a_word[ STRINGSIZE ];
    int length, character;

    printf( "hit any key\n" );
    character = getch();

    printf( "%c is the character\n", character);

    printf( "hit any key\n" );
    character = getch();

    printf( "%c is the character\n", character);

    printf( "Just checking stuff out: \n" );

    do{

        length = get_string( STRINGSIZE, a_word );
        printf( "%s is %d characters long.\n", a_word, length );
        printf ( "recounted as %d characters.\n", get_length( a_word ) );

    } while ( length != 0 );

    return 0;
}

int get_string( int bounds, char * string ){

    /* Use getchar() to safely populate a string, terminating the
     * string with a NULL ('\0') character, and returning the number of
     * characters in the string. 
     * 
     * Requires: maximum size of character array, pointer to character array
     * 
     */

    char letter = '\0';
    int offset = 0;

    while ( (letter != '\n') && (offset < (bounds - 1)) ){

        letter = string[offset++] = getchar();

    }

    string[offset] = '\0';

    return (offset - 1);
}

int get_length ( const char * to_test ){

    /* Count and return the number of characters in a given NULL terminated string
     */

    int count = 0;

    while ( to_test[count++] != '\0' );

    return (count - 2);

}

/* int getachar( void ){

    char c;

    return ( read(0, &c, 1) == 1) ? (unsigned char) c: EOF;


} */



/* reads from keypress, doesn't echo */

int getch(void)
{

    /* copied from https://stackoverflow.com/questions/3276546/how-to-implement-getch-function-of-c-in-linux
    to solve a persistent problem. Need documentation for termios.h */
    
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO ); /* bitwise operation to set binary flags */
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
    
}
