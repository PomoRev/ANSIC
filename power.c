#include <stdio.h>

int main(){

    int i, number = 3, exponent = 20, result = 1;

    for ( i = 1; i <= exponent; i++ ){

        result = result * number;

    }

    printf("%d!", result);

    return 0;

}