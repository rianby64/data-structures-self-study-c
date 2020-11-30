
#ifndef LLIST_LLIST_H
#define LLIST_LLIST_H

typedef struct llist {
  void* payload;
  struct llist *next;
} Llist;

Llist *NewEmptyLlist();
Llist *NewLlist(void *payload);
void FreeLlist(Llist *l);

Llist *Llist_add(Llist *l, void *v);

#include "llist.c"

#endif
