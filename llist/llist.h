
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

Llist *Llist_new_empty();                   // OK
Llist *Llist_new(void *payload);            // OK
void Llist_free(Llist *l);                  // OK

Llist *Llist_append(Llist *l, void *v);     // OK
Llist *Llist_add_before(Llist *l, void *v);
Llist *Llist_add_after(Llist *l, void *v);

bool Llist_del(Llist *l);                   // OK
bool Llist_del_index(Llist *l, int i);

Llist *Llist_find(Llist *l, void *v);
Llist *Llist_find_index(Llist *l, int i);

#include "llist.c"

#endif
