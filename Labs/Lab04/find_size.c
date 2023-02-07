#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    
    struct course_t {

        int  ID;           

        int  enrollment;   

        char title[32];    

        char prof[32];     
    };

    struct course_node_t {

        int       ID;

        int       enrollment;

        char*     title;

        char*     prof;

        struct course_node_t*    next;

    };
  
    printf("%lu\n",sizeof(struct course_t));
    printf("%lu\n",sizeof(struct course_node_t));

    exit(0);
}
