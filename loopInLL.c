#include <stdio.h>
#include <stdlib.h> 
#include <malloc.h> 
#include <stdbool.h>

struct node {
    struct node *next;
    char x;
};

struct node * getLL(){
    struct node *a = (struct node *) malloc(sizeof(struct node));
    struct node *b = (struct node *) malloc(sizeof(struct node));
    struct node *c = (struct node *) malloc(sizeof(struct node));
    struct node *d = (struct node *) malloc(sizeof(struct node));
    struct node *e = (struct node *) malloc(sizeof(struct node));
    struct node *f = (struct node *) malloc(sizeof(struct node));
    a->x = 'a';
    a->next = b;

    b->x = 'b';
    b->next = c;

    c->x = 'c';
    c->next = d;

    d->x = 'd';
    d->next = e;

    e->x = 'e';
    e->next = f;

    f->x = 'f';
    f->next = d;
    return a;
}

_Bool loopExists(struct node * root) {
  struct node * fast = root;
  struct node * slow = root;

  while(fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;
    if(fast == slow) return true;
  }
  return false;
}
void main() {
  struct node * root = getLL();
  puts(loopExists(root) ? "true" : "false");
}
