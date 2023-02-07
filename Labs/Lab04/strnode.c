#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "strnode.h"

struct strnode *strnode_create( char *s, int length) {
    struct strnode* this_node = malloc(sizeof(struct strnode));

    this_node->str = malloc(strlen(s)+1);
    strcpy(this_node->str,s);
    
    this_node->length = strlen(s)+1;
    
    this_node->next = NULL;

    return this_node;
}
