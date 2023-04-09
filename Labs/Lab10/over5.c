// Gordon Rose
// April 4, 2023

#include <stdio.h>
#include <string.h>
int main(int argc, char ** argv) {
    
    char acctNumberStr[10];
    printf("Enter your account number: \n");

    strcpy(acctNumberStr, argv[1]);
    printf("Your number is %s\n", acctNumberStr);
}
