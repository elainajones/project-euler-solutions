#include <stdio.h>

// Problem 10
//
// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17
// Find the sum of all the primes below two million.

void main() {
    // Store the primes here.
    int primes[2000000] = {2, 3};

    // Number of primes
    int count = 2;
    int iter = 0;

    // Test range for sanity
    // int range = 10;
    int range = 2000000;
    double sum = 2.0;

    int x, y, p;
    for (x = 2; x <= range; x++) {
        for (y = 0; y < count; y++) {
            // We only need to divide by primes.
            p = primes[y];
            if (x % p == 0) {
                // Divisible by prime so not prime.
                break;
            } else if (p > x/primes[iter]) {
                break;
            }
        }

        if (x % p != 0) {
            sum += x;
            primes[count] = x;
            count += 1;
        } else if (x >= primes[iter]*primes[iter+1]) {
            iter+=1;
        }
        // printf("test %d\t", x);
        // printf("prime %d\t", p);
        // printf("next %d\n", primes[iter]);
    }

    printf("%f\n", sum);
}
