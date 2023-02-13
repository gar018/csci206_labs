#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include <math.h>

void do_operation(struct stack* s, void* op); //proto

int main(int argc, char * argv[]) {
   struct stack* the_stack = stack_create();
   float* this_arg = malloc(4);

   for(int i = 1; i < argc; i++) {
       if (sscanf(argv[i],"%f",this_arg) > 0) {
           stack_push(the_stack,argv[i],4);

       }
       else {
            do_operation(the_stack, argv[i]);
       }
   }
   free(this_arg);
   float* result = malloc(4);
   while (!stack_isempty(the_stack)) {
        stack_pop(the_stack, result, sizeof(float));
        printf("%.6f\n",*result);    
   }
   free(result);
   stack_destroy(the_stack);
   exit(0);
}

void do_operation(struct stack* s, void* op) {
    void* ptr2 = malloc(4);
    void* ptr1 = malloc(4);
    stack_pop(s,ptr2,sizeof(ptr2));
    stack_pop(s,ptr1,sizeof(ptr1));
    float* op2 = malloc(4);
    float* op1 = malloc(4);
    sscanf(ptr2,"%f",op2);
    sscanf(ptr1,"%f",op1);
    free(ptr2);
    free(ptr1);
    float result;
    if (strcmp(op,"+")==0) {
        result=*op1+*op2;
    }
    else if (strcmp(op,"-")==0) {
        result= (*op1) - *op2;
    }
    else if (strcmp(op,"x")==0) {
        result = (*op1) * (*op2);
    }
    else if (strcmp(op,"/")==0) {
        result = *op1/ (*op2);
    }
    else if (strcmp(op,"^")==0) {
        result = powf(*op1,(*op2));
    }
    else {
        exit(1);
    }
    free(op1);
    free(op2);
    stack_push(s,&result,sizeof(float));
}
