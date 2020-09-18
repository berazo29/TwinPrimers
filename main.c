#include <stdio.h>
#include "stdlib.h"
isPrime(int n);

int main() {

    // Track the
    int numberGiven = 102;
    int prePrime = numberGiven -2;
    int postPrime = numberGiven+2;

    for (int i=0; i < numberGiven; i++){
        if (isPrime(i)){
            printf("%d \n", i);
        }
    }



    return EXIT_SUCCESS;
}

// Check prime from any n > 0
int isPrime(int n){

    // check data validity n > 0
    if ( n <= 0){
        return 0;
    }

    // Return true or 1 for first primes 1, 2
    if ( n == 1 || n == 2){
        return 1;
    }

    // Check if even
    if ( (n % 2) == 0){
        return 0;
    }

    // Generate odd numbers from 3 to n and check if not prime
    for (int i=3,j=1; i < n; j++,i=2*j+1){
        if ( (n % i) == 0){
            return 0;
        }
    }
    return 1;
}
