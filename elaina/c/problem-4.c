#include <stdio.h>

int reverse_num(int num) {
    int x = 1;
    int y = 1;

    while (num > x*10) {
        x = x*10;
    }

    int new_num = 0;
    while (num > 0) {
        int i = (num-num % x)/x;
        new_num+=i*y;
        num-=i*x;
        x = x/10;
        x = (int)x;
        y = y*10;
    }
    
    return new_num;
}

void main() {
    int x,y;
    int max_num = 0;
    for (x = 999; x > 0; x--) {
        for (y = x; y > 0; y--) {
            int m = x*y;
            int r = reverse_num(m);
            if (m == r && m > max_num) {            
                max_num = m;
            }
        };
    };

    printf("%d\n", max_num);
}
