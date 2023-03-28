/*
 * double.c
 */
#include <stdio.h>
#include <stdlib.h>

int double_value(int n);

int main (int argc, char* argv[])
{
   int n = 2;  // default, compute double n
   if (argc > 1){
      n = atoi(argv[1]);
   }
   int d = double_value(n);
   printf("Double of 2 is %d\n",d);
   d = 1;
   printf("Value of d is %d\n", d);
   printf("How are you?\n");

   return 0;
}

