/*
 *Gordon Rose
 *1/24/23
 *Section 02
 * Lab 02
 * Part 5: primefact
 */

/* EXPERIMENT RESULTS
 * Python Time: 2.179s
 * C Time: 0.048s
 * Overall Speed Up (Python / C):
 * 45.40x faster (than Python)
 */
#include <stdio.h>

int main(void) {
    int n = 2147483645;
    int i = 2;

    while (i <= n) {
        if (n%i==0) {
            printf("%d\n",i);
            n = n/i;
        }
        else {
            i = i + 1;
        }
    }

    return 0;
}
