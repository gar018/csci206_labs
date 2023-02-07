#include <stdio.h>
#include "node.h"

// global variables (data segment)

struct node *n1, *n2, *n3, *p;

//------------ MY MAIN FUNCTION --------------------

int main(int argc, char *argv[]) {

  // create strnodes
  n1 = node_create("hello", 6);
  n2 = node_create("there", 6);
  n3 = node_create("prof", 5);

  printf("node_test running...\n");

  // manually "link" the nodes together.
  n1->next = n2;
  n2->next = n3;
  n3->next = NULL;

  // p points to node n1 initially
  p = n1;

  while (p != NULL) {
    // Complete this line to print the current node's string and   
    // the stored length (do not use strlen!)
    printf("str: %s - length: %d\n",(char*)p->data,p->size); // TODO

    // TODO: add code to move p to point to next node
    // until you add this line, this program will have an infinite loop.
    p = p->next;
  }


  return 0;
}

