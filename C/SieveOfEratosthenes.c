#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//takes as arguments the lower and upper bounds of a certain range and returns a vector with all prime numbers within the given range
int* sieve_of_eratosthenes(const int lower, const int upper) {
    bool is_prime[upper+1];
    for (int i = 2; i<=upper; i++) is_prime[i] = true;
    is_prime[0] = false;
    is_prime[1] = false;

    int amount = 0;
    for (int i = 2; i<=upper; i++) {
        if (is_prime[i]) {
            for (int j = i*2; j<=upper; j+=i) {
                is_prime[j] = false;
            }
            if (i >= lower) amount++;
        }
    }

    int primes[amount+1];
    primes[0] = amount;
    int j = 1;
    for (int i = 1; i<=sizeof(is_prime)/sizeof(is_prime[0]); i++) {
        if (i >= lower && is_prime[i]) primes[j++] = i;
    }
    return primes;
}

int main() {
    int lower, upper;
    printf("This method finds all prime numbers between a range\n");
    printf("Enter the lower bound of the range\n");
    scanf("%d", &lower);
    printf("Enter the upper bound of the range\n");
    scanf("%d", &upper);
    if (lower > upper) {
        int temp = lower;
        lower = upper;
        upper = temp;
    }
    
    const int *result = sieve_of_eratosthenes(lower, upper);
    const int size = *result;
    int primes[size];
    for (int i = 0; i<size; i++) {
        primes[i] = *(result+i+1);
    }

    if (size > 0) {
        printf("A list of all the prime numbers found within the given range:\n");
        bool first = true;
        for (int i = 0; i<size; i++) {
            if (!first) printf(", ");
            else first = false;
            printf("%d", primes[i]);
        }
        printf("\n");
    }
    else {
        printf("No prime numbers found within the given range\n");
    }
    return 0;
}
