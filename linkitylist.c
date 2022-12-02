/* linkitylist.c
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2022-12-02
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct linkity {

    int number;
    struct linkity * nextlinkinty;
    
} linkity;

linkity * addtolist (int num, linkity * startlist){

    linkity * startingpoint = startlist;

    linkity * tempelement = malloc( sizeof( linkity ));
    tempelement->number = num;

    if ( startingpoint == NULL ){

        startingpoint = tempelement;

    } else {

        tempelement->nextlinkinty = startingpoint;
        startingpoint = tempelement;

    }

    return startingpoint;

}

void printlist( linkity * toprint ){

    while ( toprint != NULL ){
        printf("[%d]", toprint->number );
        toprint = toprint->nextlinkinty;
    }
    printf("\n");
}

int main(){

    linkity * mylist = NULL;

    mylist = addtolist(14, mylist);

    printlist(mylist);

    mylist = addtolist(27, mylist);

    printlist(mylist);

    return 0;

}


