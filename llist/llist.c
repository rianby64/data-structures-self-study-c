
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

#include "llist.h"

Llist *NewEmptyLlist() {
  Llist *newl = malloc(sizeof(Llist));
  assert(newl != NULL);

  newl->payload = NULL;
  newl->next = NULL;
  newl->back = NULL;

  return newl;
}

void _freeLlistNext(Llist *l) {
  if (l->next != NULL) {
    _freeLlistNext(l->next);
    free(l->next);
  }
}

void FreeLlist(Llist *l) {
  _freeLlistNext(l);
  free(l);
}

Llist *NewLlist(void *payload) {
  Llist *newl = NewEmptyLlist();

  newl->payload = payload;

  return newl;
}

Llist *Llist_add(Llist *l, void *v) {
  assert(l != NULL);

  if (l->payload == NULL) {
    l->payload = v;

    return l;
  }

  Llist *curr = l;
  while (curr->next != NULL) {
    curr = curr->next;
  }

  Llist *newl = NewLlist(v);

  curr->next = newl;
  newl->payload = v;
  newl->back = curr;

  return newl;
}

bool Llist_del(Llist *l) {
  assert(l != NULL);

  while (true) {
    if (l->back != NULL && l->next != NULL) {
      l->next->back = l->back;
      l->back->next = l->next;
      break;
    }

    if (l->back != NULL && l->next == NULL) {
      l->back->next = NULL;
      break;
    }

    if (l->back == NULL && l->next != NULL) {
      l->next->back = NULL;
      l->next = l->next->next;
      break;
    }

    break;
  }

  l->next = NULL;
  l->payload = NULL;
  FreeLlist(l);
  return true;
}