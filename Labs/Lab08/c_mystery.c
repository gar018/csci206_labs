#include <stdio.h>

int main() {
    
    int unused = 0xFEEDBEEF;
    int t0 = 0;
    int s2 = 0;
    int t3 = 0;
    do {
        s2 += t0;
        t0++;
        t3 = t0 - 10;
    } while (t3 <= 0);
    
    int x = s2;
    printf("%p\n%p\n",unused,x);

    return x;
}
