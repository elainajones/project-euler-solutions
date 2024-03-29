// The prime factors of 13195 are 5, 7, 13, and 29.
// What is the largest prime prime factor of the number 600851475143?
#include <stdio.h>

void main() {
    long num = 600851475143;
    //long num = 13195;
    long prime = 2;
    
    long x;
    long y;
    for (x = 2; prime < num; x++) {
        for (y = 2; y < x && y < num; y++) {
            if (x % y == 0 && y < x) {
                x += 1;
                y = 2;
            }
        }
        prime = x;
        if (num % prime == 0 && num > prime) {
            num = num / prime;
            prime = 2;
        }
    }
    printf("%ld\n", num);
}
