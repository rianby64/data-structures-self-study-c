
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

#include "llist.h"

Llist* Llist_new_empty() {
  Llist *newl = malloc(sizeof(Llist));
  assert(newl != NULL);

  newl->payload = NULL;
  newl->next = NULL;
  newl->back = NULL;

  newl->head = newl;
  newl->tail = newl;
  return newl;
}

void _free_Llist_next(Llist *l) {
  assert(l != NULL);

  if (l->next != NULL) {
    _free_Llist_next(l->next);
    free(l->next);
    l->next = NULL;
  }
}

void Llist_free(Llist *l) {
  assert(l != NULL);

  _free_Llist_next(l);
  free(l);
  l = NULL;
}

Llist* Llist_new(void *payload) {
  Llist *newl = Llist_new_empty();

  newl->payload = payload;

  return newl;
}

Llist* Llist_head(Llist *l) {
  assert(l != NULL);

  return l->head;
}

Llist* Llist_tail(Llist *l) {
  assert(l != NULL);

  return l->tail;
}

Llist* Llist_append(Llist *l, void *v) {
  assert(l != NULL);

  if (l->payload == NULL) {
    l->payload = v;

    return l;
  }

  Llist *newl = Llist_new(v);
  l->tail->next = newl;
  newl->back = l->tail;
  newl->payload = v;

  Llist *curr = newl;
  while (curr->back != NULL) {
    curr->head = l->head;
    curr->tail = newl;
    curr = curr->back;
  }

  curr->tail = newl;

  return newl;
}

Llist* Llist_prepend(Llist *l, void *v) {
  assert(l != NULL);

  if (l->payload == NULL) {
    l->payload = v;

    return l;
  }

  Llist *newl = Llist_new(v);
  l->back = newl;
  newl->next = l;
  newl->back = NULL;
  newl->payload = v;

  Llist *curr = newl;
  while (curr->next != NULL) {
    curr->head = newl;
    curr->tail = l->tail;
    curr = curr->next;
  }

  curr->head = newl;
  curr->tail = l->tail;

  return newl;
}

bool Llist_del(Llist *l) {
  assert(l != NULL);

  Llist *head = l->head;
  Llist *tail = l->tail;

  while (true) {
    if (l->back != NULL && l->next != NULL) {
      l->next->back = l->back;
      l->back->next = l->next;

      break;
    }

    if (l->back != NULL && l->next == NULL) {
      tail = l->back;
      l->back->next = NULL;

      break;
    }

    if (l->back == NULL && l->next != NULL) {
      head = l->next;
      l->next->back = NULL;
      l->next = l->next->next;

      break;
    }

    break;
  }

  Llist *curr = head;
  while (curr->next != NULL) {
    curr->head = head;
    curr->tail = tail;
    curr = curr->next;
  }

  curr->head = head;
  curr->tail = tail;

  l->next = NULL;
  l->payload = NULL;
  Llist_free(l);

  return true;
}