
#ifndef LLIST_LLIST_H
#define LLIST_LLIST_H

#include <stdbool.h>

typedef struct llist {
  void* payload;
  struct llist *next;
  struct llist *back;

  struct llist *head;
  struct llist *tail;
} Llist;

Llist *NewEmptyLlist();
Llist *NewLlist(void *payload);
void FreeLlist(Llist *l);

Llist *Llist_append(Llist *l, void *v);
Llist *Llist_add_before(Llist *l, void *v);
Llist *Llist_add_after(Llist *l, void *v);

bool Llist_del(Llist *l);

#include "llist.c"

#endif
