#include <stdio.h>
#include <stdlib.h>
#include "list.h"

node* mk_node(int val){
  node* x = malloc(sizeof(node));
  x->val = val;
  x->next = NULL;
  return x;
}
/* de allocate all memory for a list.
   does not work with cycles! */
void ll_destroy(node* list){
  if (list == NULL)
    return;
  if (list->next != NULL)
    ll_destroy(list->next);
  free (list);
}

void ll_append(node* list, node* new_node){
  //move to the end of the list
  while (list->next != NULL){
    list = list->next;
  }
  // and link the new node at the end
  list->next = new_node;
}
void ll_print(const node* list){
  printf("[");
  while(list != NULL){
    printf("%d", list->val);
    if (list->next != NULL){
      printf(", ");
    }
    list = list->next;
  }
  printf("]\n");
}


/* FIXME: this function is buggy. */
int ll_equal(const node* a, const node* b) {

  /* base case, empty lists are equal */
  if (a == NULL || b == NULL)
  	return a == b;

  /* check if the first element is the same, if not we're done!  */
	if (a->val != b->val)
		return 0;

  /* recurse if they are the same */
  return ll_equal(a->next, b->next);
}

/* TODO: write this function, see lab writeup */
int ll_has_cycle(node *head) {
  node* t = head; //tortoise
  node* h = head; //hare

  do {
    if (h==NULL || h->next==NULL) return 0;
    h = h->next->next;
    t = t->next;
  } while (t != h);
  return 1;
}
