#include <stdio.h>
#include <stdlib.h>

int isPrime(int n);
int isTwinPrime(int n);

int main(int argc, char* argv[argc+1]) {

    // File name from the arguments
    if ( argc != 2 ){
        printf("Two arguments are required.\n");
        return EXIT_FAILURE;
    }

    // Declare the read and write pointers
    FILE* fp;

    fp = fopen(argv[1], "r");

    // Check if the file unable to open
    if (fp == NULL){
        printf("Unable to read the file.\n");
        return EXIT_FAILURE;
    }

    // Get the number from file
    int numberRead;

    while (fscanf(fp, "%d\n", &numberRead ) != EOF ){

        // Check for twin prime, print yes or no
        if ( isTwinPrime( numberRead ) ){
            printf("yes\n");
        } else{
            printf("no\n");
        }
    }

    // Close the read file
    fclose(fp);

    return EXIT_SUCCESS;
}

// Check prime from any n > 0; return 1 for true or 0 for false
int isPrime(int n){

    // check data validity n > 1
    if ( n <= 1){
        return 0;
    }

    // Return true or 1 for first primes 1, 2
    if ( n == 2){
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

    // check data validity n > 2
    if ( numberGiven < 3 ){
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
