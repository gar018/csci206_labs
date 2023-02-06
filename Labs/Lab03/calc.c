/*
 * File name: cmd_args.c
 * Compile with: gcc -std=c99 cmd_args.c -o cmd_args
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isvalid(char str[]); //prototype
int isinteger(char str[]); //prototype
void add_args(int argc, char * argv[]);
void len_args(int argc, char * argv[]);
void mult_args(int argc, char * argv[]);
void div_args(int argc, char * argv[]);

int main(int argc, char * argv[]) {
    
    if (argc == 1) {
        printf("Usage: ./calc <operation> <arguments...>\n");
        exit(1);
    }

    //indicates which function to use later in the program
    //var = 0 -> invalid function name
    //var = 1 -> add fn
    //var = 2 -> len fn
    //var = 3 -> mult fn
    //var = 4 -> div fn
    int use_function = isvalid(argv[1]);


    if (use_function == 0){//checks for valid fn name
            printf("Unsupported function, try: add, mult, div, or len\n");
            exit(1);
    }   


    else { //looks at each argument, and performs the necessary operation to each

        if (use_function == 1) {
            add_args(argc, argv);
        }
        else if(use_function == 2) {
            len_args(argc,argv);
        }
        else if(use_function == 3) {
            mult_args(argc,argv);
        }
        else if(use_function == 4) {
            div_args(argc,argv);
        }
        else { 
            //this statement should NEVER be reached. otherwise something is very wrong
            exit(2);
        }

    }
    exit(0);
}

void add_args(int argc, char * argv[]) {

    if (argc < 4) {//checks for valid number of args
        printf("More arguments are needed\n");
        exit(1);
    }
    long int total = 0;
    for (int i = 2; i < argc; i++){
        if(isinteger(argv[i]) == 1) {
            total += strtol(argv[i],NULL,10);
        }
        else {
            printf("Invalid operands\n");
            exit(1);
        }
    }
    printf("%ld\n",total);
}

void len_args(int argc, char * argv[]) {

    if (argc < 3) {//checks for valid number of args
        printf("More arguments are needed\n");
        exit(1);
    }
    long int total = 0;
    for (int i = 2; i < argc; i++){
        total += strlen(argv[i]);
    }
    printf("%ld\n",total);
}

void mult_args(int argc, char * argv[]) {

    if (argc < 4) {//checks for valid number of args
        printf("More arguments are needed\n");
        exit(1);
    }
    long int total = strtol(argv[2],NULL,10);
    for (int i = 3; i < argc; i++){
        if(isinteger(argv[i]) == 1) {
            total *= strtol(argv[i],NULL,10);
        }
        else {
            printf("Invalid operands\n");
            exit(1);
        }
    }
    printf("%ld\n",total);
}

void div_args(int argc, char * argv[]) {

    if (argc < 4) {//checks for valid number of args
        printf("More arguments are needed\n");
        exit(1);
    }
    long int result = strtol(argv[2],NULL,10);
    for (int i = 3; i < argc; i++){
        if (strtol(argv[i],NULL,10) == 0) {
            printf("Divide by zero\n");
            exit(1);
        }
        else if(isinteger(argv[i]) == 1) {
            result = result / strtol(argv[i],NULL,10);
        }
        else {
            printf("Invalid operands\n");
            exit(1);
        }
    }
    printf("%ld\n",result);
}



int isvalid(char str[]) {

    char add[] = "add";
    char len[] = "len";
    char mult[] = "mult";
    char div[] = "div";

    if(strcmp(str,add)==0)
        return 1;
    if(strcmp(str,len)==0)
        return 2;
    if(strcmp(str,mult)==0)
        return 3;
    if(strcmp(str,div)==0)
        return 4;
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
