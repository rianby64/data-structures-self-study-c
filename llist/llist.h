
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

void _free_Llist_next(Llist *l);

Llist* Llist_new_empty();                      // OK
Llist* Llist_new(void *payload);               // OK
void Llist_free(Llist *l);                     // OK

Llist* Llist_head(Llist *l);                   // OK
Llist* Llist_tail(Llist *l);                   // OK

Llist* Llist_append(Llist *l, void *v);        // OK
Llist* Llist_prepend(Llist *l, void *v);       // OK
Llist* Llist_add_before(Llist *l, void *v);
Llist* Llist_add_after(Llist *l, void *v);

bool Llist_del(Llist *l);                      // OK
bool Llist_del_by_index(Llist *l, int i);
bool Llist_del_by_value(Llist *l, void *v);

Llist* Llist_find(Llist *l, void *v);
Llist* Llist_find_by_index(Llist *l, int i);
Llist* Llist_find_by_value(Llist *l, void *i); // OK

#include "llist.c"

#endif
