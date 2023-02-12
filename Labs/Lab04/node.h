#ifndef NODE_H_
#define NODE_H_


struct node {
    void*                data;
    int                  size;
    struct node*         next;
};

struct node *node_create(void* d, int size);
void node_destroy(struct node* n);
#endif
