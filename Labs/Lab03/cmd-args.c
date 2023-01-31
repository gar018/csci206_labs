/*
 * File name: cmd_args.c
 * Compile with: gcc -std=c99 cmd_args.c -o cmd_args
 */
#include <stdio.h>
#include <string.h>

int isvalid(char str[]); //prototype
int isinteger(char str[]); //prototype

int main(int argc, char * argv[]) {

    if (argc < 4) {
        printf("Incorrect number of arguments.\n");
        return 0;
    }
    else {
        if (isvalid(argv[1]) == 1)
            printf("\"%s\" is a valid command\n",argv[1]);
        else
            printf("\"%s\" is an invalid command\n",argv[1]);
        for (int i = 2; i < argc; i++){
            if(isinteger(argv[i]) == 1)
                printf("%s is an integer\n",argv[i]);
            else
                printf("%s is not an integer\n",argv[i]);
        }
    }
    //for (int i = 0; i < argc; ++i)
	 // printf("The %dth argument is %s\n", i, argv[i]);*/
    return 0;
}

int isvalid(char str[]) {
    char add[] = "add";
    char sub[] = "sub";
    char mult[] = "mult";
    char div[] = "div";

    if(strcmp(str,add)==0)
        return 1;
    if(strcmp(str,sub)==0)
        return 1;
    if(strcmp(str,mult)==0)
        return 1;
    if(strcmp(str,div)==0)
        return 1;
    return 0;
}

int isinteger(char str[]) {
    for(int i = 0; i < strlen(str); i++) {
        if (!(str[i] >= '0' && str[i] <= '9')) {
            return 0;
        }
    }
    return 1;
}
