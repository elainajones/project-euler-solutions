#include <stdio.h>

void main() {
    int sum = 0;
    int max = 1000;
    int i;
    for (i = 1; i < max; i++) {
        if (i*3 > max && i*5 > max) {
            break;
        }
        if (i*3 < max) {
            sum+=i*3;
        }
        if (i*5 < max && (i*5) % 3 != 0) {
            sum+=i*5;
        }
    }
    printf("%d\n",sum);
}
