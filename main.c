
#include <stdlib.h>
#include <assert.h>

#include "llist/llist.h"

int main() {

  void *expected1 = (void *)55;
  void *expected2 = (void *)66;
  void *expected3 = (void *)77;

  Llist *newllist = NewEmptyLlist();
  Llist *added1 = Llist_add(newllist, expected1);
  Llist *added2 = Llist_add(newllist, expected2);
  Llist *added3 = Llist_add(newllist, expected3);

  void *actual1 = newllist->payload;
  void *actual2 = newllist->next->payload;
  void *actual3 = newllist->next->next->payload;

  FreeLlist(newllist);

  return 0;
}