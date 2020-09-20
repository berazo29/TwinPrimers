#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

isPrime(int n);
int isTwinPrime(int n);

int main() {

    // Track the 3,14,19,23,31,0,5;
    int n = 512;
    printf("%d", isTwinPrime( n ) );

    // Open and read the file
    // Create a file for outputs
    // Feed the data
    // Check if Twin prime
    // Write in the file for outputs
    // Close the read and write files

    return EXIT_SUCCESS;
}

// Check prime from any n > 0; return 1 for true or 0 for false
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

// Check if prime twin from any n > 0; return 1 for true or 0 for false
int isTwinPrime(int numberGiven){

    // Declare the bounces for the twins
    int prePrime = numberGiven - 2;
    int postPrime = numberGiven + 2;

    // check data validity n > 0
    if ( numberGiven <= 0){
        return 0;
    }

    // Check if prime
    if (isPrime(numberGiven)){

        // Check if twin prime
        if ( isPrime(prePrime) || isPrime(postPrime) ){
            return 1;

        } else{
            return 0;
        }

    } else{
        return 0;
    }

}
