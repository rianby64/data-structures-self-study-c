
#include "acutest.h"
#include "llist.h"

void test_newemptyllist(void) {
  Llist *newemptyllist = NewEmptyLlist();

  TEST_ASSERT_(newemptyllist != NULL, "NewEmptyLlist expected to be not NULL");

  FreeLlist(newemptyllist);
}

void test_newllist(void) {
  void *expected = (void *)55;
  Llist *newllist = NewLlist(expected);
  void *actual = newllist->payload;

  TEST_ASSERT_(newllist != NULL, "NewLlist expected to be not NULL");
  TEST_ASSERT_(expected == actual, "NewList->payload is defined");

  FreeLlist(newllist);
}

void test_newemptyllist_add_one_item(void) {
  void *expected = (void *)55;
  Llist *newllist = NewEmptyLlist();
  Llist *added = Llist_add(newllist, expected);

  void *actual = newllist->payload;

  TEST_ASSERT_(newllist != NULL, "NewLlist expected to be not NULL");
  TEST_ASSERT_(newllist->next == NULL, "NewLlist has no next");
  TEST_ASSERT_(expected == actual, "NewList->payload is defined");

  FreeLlist(newllist);
}

void test_newemptyllist_add_two_items(void) {
  void *expected1 = (void *)55;
  void *expected2 = (void *)66;

  Llist *newllist = NewEmptyLlist();
  Llist *added1 = Llist_add(newllist, expected1);
  Llist *added2 = Llist_add(added1, expected2);

  void *actual1 = newllist->payload;
  void *actual2 = newllist->next->payload;

  TEST_ASSERT_(newllist != NULL, "NewLlist expected to be not NULL");
  TEST_ASSERT_(newllist == added1, "NewLlist equals to added if it's first item");
  TEST_ASSERT_(newllist->next == added2, "NewLlist has no next");
  TEST_ASSERT_(expected1 == actual1, "NewList->payload is defined with the expected1");
  TEST_ASSERT_(expected2 == actual2, "NewList->next->payload is defined with the expected2");

  FreeLlist(newllist);
}

void test_newemptyllist_add_from_head_add_two_items(void) {
  void *expected1 = (void *)55;
  void *expected2 = (void *)66;

  Llist *newllist = NewEmptyLlist();
  Llist *added1 = Llist_add(newllist, expected1);
  Llist *added2 = Llist_add(newllist, expected2);

  void *actual1 = newllist->payload;
  void *actual2 = newllist->next->payload;

  TEST_ASSERT_(newllist != NULL, "NewLlist expected to be not NULL");
  TEST_ASSERT_(newllist == added1, "NewLlist equals to added if it's first item");
  TEST_ASSERT_(newllist->next == added2, "NewLlist has no next");
  TEST_ASSERT_(expected1 == actual1, "NewList->payload is defined with the expected1");
  TEST_ASSERT_(expected2 == actual2, "NewList->next->payload is defined with the expected2");
  TEST_ASSERT_(newllist->next->next == NULL, "NewLlist within two nexts is NULL");

  FreeLlist(newllist);
}

void test_newemptyllist_add_three_items(void) {
  void *expected1 = (void *)55;
  void *expected2 = (void *)66;
  void *expected3 = (void *)77;

  Llist *newllist = NewEmptyLlist();
  Llist *added1 = Llist_add(newllist, expected1);
  Llist *added2 = Llist_add(added1, expected2);
  Llist *added3 = Llist_add(added2, expected3);

  void *actual1 = newllist->payload;
  void *actual2 = newllist->next->payload;
  void *actual3 = newllist->next->next->payload;

  TEST_ASSERT_(newllist != NULL, "NewLlist expected to be not NULL");
  TEST_ASSERT_(newllist == added1, "NewLlist is added1");
  TEST_ASSERT_(newllist->next == added2, "NewLlist->next is added2");
  TEST_ASSERT_(newllist->next->next == added3, "NewLlist->next->next is added3");
  TEST_ASSERT_(expected1 == actual1, "NewList->payload is defined with the expected1");
  TEST_ASSERT_(expected2 == actual2, "NewList->next->payload is defined with the expected2");
  TEST_ASSERT_(expected3 == actual3, "NewList->next->next->payload is defined with the expected3");
  TEST_ASSERT_(newllist->next->next->next == NULL, "NewLlist within three nexts is NULL");

  FreeLlist(newllist);
}

void test_newemptyllist_add_from_head_add_three_items(void) {
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

  TEST_ASSERT_(newllist != NULL, "NewLlist expected to be not NULL");
  TEST_ASSERT_(newllist == added1, "NewLlist is added1");
  TEST_ASSERT_(newllist->next == added2, "NewLlist->next is added2");
  TEST_ASSERT_(newllist->next->next == added3, "NewLlist->next->next is added3");
  TEST_ASSERT_(expected1 == actual1, "NewList->payload is defined with the expected1");
  TEST_ASSERT_(expected2 == actual2, "NewList->next->payload is defined with the expected2");
  TEST_ASSERT_(expected3 == actual3, "NewList->next->next->payload is defined with the expected3");
  TEST_ASSERT_(newllist->next->next->next == NULL, "NewLlist within three nexts is NULL");

  FreeLlist(newllist);
}

TEST_LIST = {
  {"NewEmptyLlist() returns an empty list", test_newemptyllist},
  {"NewLlist() returns a list", test_newllist},
  {"NewEmptyLlist() add one item", test_newemptyllist_add_one_item},
  {"NewEmptyLlist() add two items", test_newemptyllist_add_two_items},
  {"NewEmptyLlist() add two items, second item added from the head", test_newemptyllist_add_from_head_add_two_items},
  {"NewEmptyLlist() add three items", test_newemptyllist_add_three_items},
  {"NewEmptyLlist() add three items, add then from the head", test_newemptyllist_add_from_head_add_three_items},
  {0}
};
