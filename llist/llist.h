
#ifndef LLIST_LLIST_H
#define LLIST_LLIST_H

typedef struct llist {
  void* payload;
  struct llist *next;
} Llist;

Llist *NewEmptyLlist();
Llist *NewLlist(void *payload);
Llist *add(Llist *l, void *v);

#endif