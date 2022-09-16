/*  Classic Hello World Code 
 *  Frank Emanuel (emanuef@algonquincollege.com)
 *  CST8234 ANSI C 
 */

#include <stdio.h>

int main() {

    for (int i = 1; i < 11; i++){

        printf("%d div %d remain %d\n", 
            i, i / 3, i % 3);
    }
    
    return 0;

} 