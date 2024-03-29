#include <stdio.h>

void main() {
    //int num = 2000000;
    int num = 10;
    int prime = 2;
    int next = prime;
    int sum = prime;

    int x, y;
    for (x = 2; x <= num; x++) {
        for (y = prime; y < x; y++) {
            if (x % y == 0 && y < x) {
                x += 1;
                y = 2;
            } else if (y > x / prime) {
                break;
            } else if (x >= prime*next) {
                prime = next;
            }
        }
        
        if (x % prime != 0 && x <= num) {
            sum += x;
            next = x;
        }
        printf("test %d\t", x); printf("prime %d\t", prime); printf("next %d\n", next);
    }
    
    printf("%d\n", sum);
}

/*
#include <stdio.h>

void main() {
    int primes[1000000] = {2, 3};

    int p_count = 2;
    int p_iter = 0;

    int p_num; 
    double p_sum = 2.0;

    int test_num, i;
    for (test_num = 2; test_num <= 2000000; test_num++) {
        for (i = 0; i < p_count; i++) {
            p_num = primes[i];
            if (test_num % p_num == 0) {
                break;
            } else if (p_num > test_num/primes[p_iter]) {
                break;
            }
        }

        if (test_num % p_num != 0) {
            p_sum+=test_num;
            primes[p_count]=test_num;
            p_count+=1;
        } else if (test_num >= primes[p_iter]*primes[p_iter+1]) {
            p_iter+=1;
        }
    }
    
    printf("%f\n", p_sum);
}
*/
