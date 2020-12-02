
#ifndef LLIST_LLIST_H
#define LLIST_LLIST_H

typedef struct llist {
  void* payload;
  struct llist *next;
  struct llist *back;
} Llist;

Llist *NewEmptyLlist();
Llist *NewLlist(void *payload);
void FreeLlist(Llist *l);

Llist *Llist_add(Llist *l, void *v);
bool Llist_del(Llist *l);

#include "llist.c"

#endif
