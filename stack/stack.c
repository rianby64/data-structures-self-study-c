
#include <assert.h>
#include <stdlib.h>

#include "stack.h"
#include "../llist/llist.h"

Stack* Stack_new() {
  Stack *news = malloc(sizeof(Stack));
  assert(news != NULL);

  news->list = Llist_new_empty();
  return news;
}

void Stack_free(Stack *s) {
  assert(s != NULL);
  assert(s->list != NULL);

  Llist_free(s->list);
  s->list = NULL;

  free(s);
  s = NULL;
}

void Stack_push(Stack *s, void *v) {
  assert(s != NULL);
  assert(s->list != NULL);

  Llist_append(s->list, v);
}

void* Stack_pop(Stack *s) {
  assert(s != NULL);
  assert(s->list != NULL);

  Llist *tail = s->list->tail;
  if (tail != NULL) {
    void *v = tail->payload;
    Llist_del(tail);

    return v;
  }

  return NULL;
}