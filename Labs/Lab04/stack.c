
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
#include "node.h"
#include "node.c"

struct stack* stack_create() {
    struct stack* this_stack = malloc(sizeof(struct stack));
    this_stack->top=NULL;
    return this_stack;
}

int stack_isempty(struct stack* s) {
    if (s->top == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

void stack_destroy(struct stack* s) {
    while (stack_isempty(s) == 0) {
        stack_pop(s, NULL, 0);
    }
    free(s);
    s = NULL;
}

void stack_push(struct stack* s, void* src, int size) {
    struct node* this_node = node_create(src, size);
    this_node->next = s->top;
    s->top = this_node;
}

void stack_pop(struct stack* s, void* dest, int size) {
    struct node* this_node = s->top;
    if (dest != NULL) {
        memcpy(dest, this_node->data, size);
    }
    s->top = this_node->next;
    node_destroy(this_node);
}


