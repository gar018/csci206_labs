/* nogood.c -- a program with errors

Stephen Prata - C Primer Plus 6/e - Listing 2.4

 compile with: gcc

*/

#include <stdio.h>

int main(void)

{
   // int z;

   int n = 5;

   int n2 = n * n;

   int n3 = n2 * n;

 

    printf("n = %d, n squared = %d, n cubed = %d\n", n, n2, n3);

 

    return 0;

}




