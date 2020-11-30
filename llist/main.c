
#include <stdlib.h>
#include <assert.h>

#include "llist.h"
#include "llist.c"

int main() {
  Llist *w = NewLlist(44);
  assert(w != NULL);

  Llist *added = add(w, 55);

  int x = (int)w->payload;

  assert(x == 44);
  assert(added->payload == 55);

  free(added);
  free(w);

  Llist *y = NewLlist(66);
  assert(y != NULL);
  int yv = (int)y->payload;

  assert(yv == 66);

  return 0;
}