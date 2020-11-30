
#include <assert.h>
#include <stdlib.h>

#include "llist.h"

Llist *NewEmptyLlist() {
  Llist *newl = malloc(sizeof(Llist));
  assert(newl != NULL);

  newl->payload = NULL;
  newl->payload = NULL;

  return newl;
}

Llist *NewLlist(void *payload) {
  Llist *newl = NewEmptyLlist();

  newl->payload = payload;

  return newl;
}

Llist *add(Llist *l, void *v) {
  assert(l != NULL);

  Llist *newl = NewLlist(v);

  l->next = newl;
  newl->payload = v;

  return newl;
}