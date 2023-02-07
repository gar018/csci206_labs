#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "node.h"

struct node *node_create( void* d, int size) {
    struct node* this_node = malloc(sizeof(struct node));

    this_node->data = malloc(size);
    memcpy(this_node->data,d,size);
    
    this_node->size = size;
    
    this_node->next = NULL;

    return this_node;
}

void node_destroy( struct node* n ) {
    free(n->data);
    free(n);
}
