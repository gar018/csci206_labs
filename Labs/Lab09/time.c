/*
 * time.c
 */
#include <stdio.h>
#include <time.h>
 
int main(void)
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
 
    printf ("it is now: %s\n", asctime(tm));
    return 0;
}
