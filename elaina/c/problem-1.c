// If we list all the natural numbers below 10 that are multiples of 3 
// or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
//
// Find the sum of all the multiples of 3 or 5 below 1000.
#include <stdio.h>

void main() {
    int max = 1000;
    int sum = 0;

    int i;
    for (i = 1; i < max; i++) {
        if (i*3 > max && i*5 > max) {
            break;
        }
        if (i*3 < max) {
            sum += i*3;
        }
        if (i*5 < max && (i*5) % 3 != 0) {
            sum += i*5;
        }
    }

    printf("%d\n", sum);
}
