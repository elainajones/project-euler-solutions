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

