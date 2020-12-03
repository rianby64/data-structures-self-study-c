
#include <stdbool.h>
#include "acutest.h"
#include "llist.h"

void test_newemptyllist(void) {
  Llist *newemptyllist = Llist_new_empty();

  TEST_ASSERT_(newemptyllist != NULL, "NewEmptyLlist expected to be not NULL");

  Llist_free(newemptyllist);
}

void test_newllist(void) {
  void *expected = (void *)55;
  Llist *newllist = Llist_new(expected);
  void *actual = newllist->payload;

  TEST_ASSERT_(newllist != NULL, "Llist_new expected to be not NULL");
  TEST_ASSERT_(expected == actual, "NewList->payload is defined");

  Llist_free(newllist);
}

void test_newemptyllist_append_one_item(void) {
  void *expected = (void *)55;
  Llist *newllist = Llist_new_empty();
  Llist *added = Llist_append(newllist, expected);

  void *actual = newllist->payload;

  TEST_ASSERT_(newllist != NULL, "Llist_new expected to be not NULL");
  TEST_ASSERT_(newllist->next == NULL, "Llist_new has no next");
  TEST_ASSERT_(expected == actual, "NewList->payload is defined");

  Llist_free(newllist);
}

void test_newemptyllist_append_two_items(void) {
  void *expected1 = (void *)55;
  void *expected2 = (void *)66;

  Llist *newllist = Llist_new_empty();
  Llist *added1 = Llist_append(newllist, expected1);
  Llist *added2 = Llist_append(added1, expected2);

  void *actual1 = newllist->payload;
  void *actual2 = newllist->next->payload;

  TEST_ASSERT_(newllist != NULL, "Llist_new expected to be not NULL");
  TEST_ASSERT_(newllist == added1, "Llist_new equals to added if it's first item");
  TEST_ASSERT_(newllist->next == added2, "Llist_new has no next");
  TEST_ASSERT_(expected1 == actual1, "NewList->payload is defined with the expected1");
  TEST_ASSERT_(expected2 == actual2, "NewList->next->payload is defined with the expected2");

  Llist_free(newllist);
}

void test_newemptyllist_append_from_head_append_two_items(void) {
  void *expected1 = (void *)55;
  void *expected2 = (void *)66;

  Llist *newllist = Llist_new_empty();
  Llist *added1 = Llist_append(newllist, expected1);
  Llist *added2 = Llist_append(newllist, expected2);

  void *actual1 = newllist->payload;
  void *actual2 = newllist->next->payload;

  TEST_ASSERT_(newllist != NULL, "Llist_new expected to be not NULL");
  TEST_ASSERT_(newllist == added1, "Llist_new equals to added if it's first item");
  TEST_ASSERT_(newllist->next == added2, "Llist_new has no next");
  TEST_ASSERT_(expected1 == actual1, "NewList->payload is defined with the expected1");
  TEST_ASSERT_(expected2 == actual2, "NewList->next->payload is defined with the expected2");
  TEST_ASSERT_(newllist->next->next == NULL, "Llist_new within two nexts is NULL");

  Llist_free(newllist);
}

void test_newemptyllist_append_three_items(void) {
  void *expected1 = (void *)55;
  void *expected2 = (void *)66;
  void *expected3 = (void *)77;

  Llist *newllist = Llist_new_empty();
  Llist *added1 = Llist_append(newllist, expected1);
  Llist *added2 = Llist_append(added1, expected2);
  Llist *added3 = Llist_append(added2, expected3);

  void *actual1 = newllist->payload;
  void *actual2 = newllist->next->payload;
  void *actual3 = newllist->next->next->payload;

  TEST_ASSERT_(newllist != NULL, "Llist_new expected to be not NULL");
  TEST_ASSERT_(newllist == added1, "Llist_new is added1");
  TEST_ASSERT_(newllist->next == added2, "Llist_new->next is added2");
  TEST_ASSERT_(newllist->next->next == added3, "Llist_new->next->next is added3");
  TEST_ASSERT_(expected1 == actual1, "NewList->payload is defined with the expected1");
  TEST_ASSERT_(expected2 == actual2, "NewList->next->payload is defined with the expected2");
  TEST_ASSERT_(expected3 == actual3, "NewList->next->next->payload is defined with the expected3");
  TEST_ASSERT_(newllist->next->next->next == NULL, "Llist_new within three nexts is NULL");

  TEST_ASSERT_(newllist->head == added1, "Added1 head is added1");
  TEST_ASSERT_(newllist->tail == added3, "Added1 tail is added3");
  TEST_ASSERT_(newllist->next == added2, "Added1 next is added2");
  TEST_ASSERT_(newllist->back == NULL, "Added1 back is NULL");

  TEST_ASSERT_(newllist->next->head == added1, "Added2 head is added1");
  TEST_ASSERT_(newllist->next->tail == added3, "Added2 tail is added3");
  TEST_ASSERT_(newllist->next->next == added3, "Added2 next is added3");
  TEST_ASSERT_(newllist->next->back == added1, "Added2 back is added1");

  TEST_ASSERT_(newllist->next->next->head == added1, "Added3 head is added1");
  TEST_ASSERT_(newllist->next->next->tail == added3, "Added3 tail is added3");
  TEST_ASSERT_(newllist->next->next->next == NULL, "Added3 next is NUL");
  TEST_ASSERT_(newllist->next->next->back == added2, "Added3 back is added2");


  Llist_free(newllist);
}

void test_newemptyllist_append_from_head_append_three_items(void) {
  void *expected1 = (void *)55;
  void *expected2 = (void *)66;
  void *expected3 = (void *)77;

  Llist *newllist = Llist_new_empty();
  Llist *added1 = Llist_append(newllist, expected1);
  Llist *added2 = Llist_append(newllist, expected2);
  Llist *added3 = Llist_append(newllist, expected3);

  void *actual1 = newllist->payload;
  void *actual2 = newllist->next->payload;
  void *actual3 = newllist->next->next->payload;

  TEST_ASSERT_(newllist != NULL, "Llist_new expected to be not NULL");
  TEST_ASSERT_(newllist == added1, "Llist_new is added1");
  TEST_ASSERT_(newllist->next == added2, "Llist_new->next is added2");
  TEST_ASSERT_(newllist->next->next == added3, "Llist_new->next->next is added3");
  TEST_ASSERT_(expected1 == actual1, "NewList->payload is defined with the expected1");
  TEST_ASSERT_(expected2 == actual2, "NewList->next->payload is defined with the expected2");
  TEST_ASSERT_(expected3 == actual3, "NewList->next->next->payload is defined with the expected3");
  TEST_ASSERT_(newllist->next->next->next == NULL, "Llist_new within three nexts is NULL");

  Llist_free(newllist);
}

void test_newemptylist_append_del_item(void) {
  void *expected = (void *)55;
  Llist *newllist = Llist_new_empty();
  Llist *added = Llist_append(newllist, expected);

  TEST_ASSERT_(newllist != NULL, "Llist_new expected to be not NULL");
  TEST_ASSERT_(newllist == added, "Llist_new is added1");
  TEST_ASSERT_(newllist->payload == expected, "Llist_new added the expected");

  bool deleted = Llist_del(newllist);
  TEST_ASSERT_(deleted == true, "deleted succeeded");
}

void test_newemptylist_append_three_items_del_item_in_the_middle(void) {
  void *expected1 = (void *)55;
  void *expected2 = (void *)66;
  void *expected3 = (void *)77;
  Llist *newllist = Llist_new_empty();
  Llist *added1 = Llist_append(newllist, expected1);
  Llist *added2 = Llist_append(newllist, expected2);
  Llist *added3 = Llist_append(newllist, expected3);

  TEST_ASSERT_(newllist != NULL, "Llist_new expected to be not NULL");
  TEST_ASSERT_(newllist == added1, "Llist_new has added1");
  TEST_ASSERT_(newllist->next == added2, "Llist_new has added2");
  TEST_ASSERT_(newllist->next->next == added3, "Llist_new has added3");
  TEST_ASSERT_(newllist->next->next->next == NULL, "Llist_new has no 4th item");

  TEST_ASSERT_(newllist->back == NULL, "Llist_new back is NULL");
  TEST_ASSERT_(newllist->next->back == added1, "Llist_new 2nd item has back === 1st item");
  TEST_ASSERT_(newllist->next->next->back == added2, "Llist_new 3rd item has back === 2nd item");

  TEST_ASSERT_(added1->back == NULL, "added1 back is NULL");
  TEST_ASSERT_(added2->back == added1, "added2 back is added1");
  TEST_ASSERT_(added3->back == added2, "added3 back is added2");

  TEST_ASSERT_(newllist->payload == expected1, "Llist_new's 1st item is expected1");
  TEST_ASSERT_(newllist->next->payload == expected2, "Llist_new's 2nd item is expected2");
  TEST_ASSERT_(newllist->next->next->payload == expected3, "Llist_new's 3rd item is expected3");

  bool deleted = Llist_del(added2);
  TEST_ASSERT_(deleted == true, "deleted succeeded");
  TEST_ASSERT_(newllist == added1, "after delete Llist_new has added1");
  TEST_ASSERT_(newllist->payload == expected1, "after delete Llist_new has expected1");
  TEST_ASSERT_(newllist->next == added3, "after delete Llist_new has added3");
  TEST_ASSERT_(newllist->next->payload == expected3, "after delete Llist_new has expected3");
  TEST_ASSERT_(newllist->next->back == added1, "after delete Llist_new has added1");
  TEST_ASSERT_(newllist->next->next == NULL, "after delete Llist_new has no 3rd item");

  TEST_ASSERT_(newllist->head == added1, "Added1 head is added1");
  TEST_ASSERT_(newllist->tail == added3, "Added1 tail is added3");
  TEST_ASSERT_(newllist->next == added3, "Added1 next is added3");
  TEST_ASSERT_(newllist->back == NULL, "Added1 back is NULL");

  TEST_ASSERT_(newllist->next->head == added1, "Added3 head is added1");
  TEST_ASSERT_(newllist->next->tail == added3, "Added3 tail is added3");
  TEST_ASSERT_(newllist->next->next == NULL, "Added3 next is NULL");
  TEST_ASSERT_(newllist->next->back == added1, "Added3 back is added1");

  Llist_free(newllist);
}

void test_newemptylist_append_three_items_del_first_item(void) {
  void *expected1 = (void *)55;
  void *expected2 = (void *)66;
  void *expected3 = (void *)77;
  Llist *newllist = Llist_new_empty();
  Llist *added1 = Llist_append(newllist, expected1);
  Llist *added2 = Llist_append(newllist, expected2);
  Llist *added3 = Llist_append(newllist, expected3);

  TEST_ASSERT_(newllist != NULL, "Llist_new expected to be not NULL");
  TEST_ASSERT_(newllist == added1, "Llist_new has added1");
  TEST_ASSERT_(newllist->next == added2, "Llist_new has added2");
  TEST_ASSERT_(newllist->next->next == added3, "Llist_new has added3");
  TEST_ASSERT_(newllist->next->next->next == NULL, "Llist_new has no 4th item");

  TEST_ASSERT_(newllist->back == NULL, "Llist_new back is NULL");
  TEST_ASSERT_(newllist->next->back == added1, "Llist_new 2nd item has back === 1st item");
  TEST_ASSERT_(newllist->next->next->back == added2, "Llist_new 3rd item has back === 2nd item");

  TEST_ASSERT_(added1->back == NULL, "added1 back is NULL");
  TEST_ASSERT_(added2->back == added1, "added2 back is added1");
  TEST_ASSERT_(added3->back == added2, "added3 back is added2");

  TEST_ASSERT_(newllist->payload == expected1, "Llist_new's 1st item is expected1");
  TEST_ASSERT_(newllist->next->payload == expected2, "Llist_new's 2nd item is expected2");
  TEST_ASSERT_(newllist->next->next->payload == expected3, "Llist_new's 3rd item is expected3");

  bool deleted = Llist_del(added1);
  newllist = added2;
  TEST_ASSERT_(deleted == true, "deleted succeeded");
  TEST_ASSERT_(newllist == added2, "after delete Llist_new has added2");
  TEST_ASSERT_(newllist->payload == expected2, "after delete Llist_new has expected2");
  TEST_ASSERT_(newllist->next == added3, "after delete Llist_new has added3");
  TEST_ASSERT_(newllist->next->payload == expected3, "after delete Llist_new has expected3");
  TEST_ASSERT_(newllist->next->back == added2, "after delete Llist_new has added2");
  TEST_ASSERT_(newllist->next->next == NULL, "after delete Llist_new has no 3rd item");

  TEST_ASSERT_(newllist->head == added2, "Added2 head is added2");
  TEST_ASSERT_(newllist->tail == added3, "Added2 tail is added3");
  TEST_ASSERT_(newllist->next == added3, "Added2 next is added3");
  TEST_ASSERT_(newllist->back == NULL, "Added2 back is NULL");

  TEST_ASSERT_(newllist->next->head == added2, "Added3 head is added2");
  TEST_ASSERT_(newllist->next->tail == added3, "Added3 tail is added3");
  TEST_ASSERT_(newllist->next->next == NULL, "Added3 next is NULL");
  TEST_ASSERT_(newllist->next->back == added2, "Added3 back is added2");


  Llist_free(newllist);
}

void test_newemptylist_append_three_items_del_last_item(void) {
  void *expected1 = (void *)55;
  void *expected2 = (void *)66;
  void *expected3 = (void *)77;
  Llist *newllist = Llist_new_empty();
  Llist *added1 = Llist_append(newllist, expected1);
  Llist *added2 = Llist_append(newllist, expected2);
  Llist *added3 = Llist_append(newllist, expected3);

  TEST_ASSERT_(newllist != NULL, "Llist_new expected to be not NULL");
  TEST_ASSERT_(newllist == added1, "Llist_new has added1");
  TEST_ASSERT_(newllist->next == added2, "Llist_new has added2");
  TEST_ASSERT_(newllist->next->next == added3, "Llist_new has added3");
  TEST_ASSERT_(newllist->next->next->next == NULL, "Llist_new has no 4th item");

  TEST_ASSERT_(newllist->back == NULL, "Llist_new back is NULL");
  TEST_ASSERT_(newllist->next->back == added1, "Llist_new 2nd item has back === 1st item");
  TEST_ASSERT_(newllist->next->next->back == added2, "Llist_new 3rd item has back === 2nd item");

  TEST_ASSERT_(added1->back == NULL, "added1 back is NULL");
  TEST_ASSERT_(added2->back == added1, "added2 back is added1");
  TEST_ASSERT_(added3->back == added2, "added3 back is added2");

  TEST_ASSERT_(newllist->payload == expected1, "Llist_new's 1st item is expected1");
  TEST_ASSERT_(newllist->next->payload == expected2, "Llist_new's 2nd item is expected2");
  TEST_ASSERT_(newllist->next->next->payload == expected3, "Llist_new's 3rd item is expected3");

  TEST_ASSERT_(newllist->head == added1, "Added1 head is added1");
  TEST_ASSERT_(newllist->tail == added3, "Added1 tail is added3");
  TEST_ASSERT_(newllist->next == added2, "Added1 next is added2");
  TEST_ASSERT_(newllist->back == NULL, "Added1 back is NULL");

  TEST_ASSERT_(newllist->next->head == added1, "Added2 head is added1");
  TEST_ASSERT_(newllist->next->tail == added3, "Added2 tail is added3");
  TEST_ASSERT_(newllist->next->next == added3, "Added2 next is added3");
  TEST_ASSERT_(newllist->next->back == added1, "Added2 back is added1");

  TEST_ASSERT_(newllist->next->next->head == added1, "Added3 head is added1");
  TEST_ASSERT_(newllist->next->next->tail == added3, "Added3 tail is added3");
  TEST_ASSERT_(newllist->next->next->next == NULL, "Added3 next is NUL");
  TEST_ASSERT_(newllist->next->next->back == added2, "Added3 back is added2");

  bool deleted = Llist_del(added3);
  TEST_ASSERT_(deleted == true, "deleted succeeded");
  TEST_ASSERT_(newllist == added1, "after delete Llist_new has added1");
  TEST_ASSERT_(newllist->payload == expected1, "after delete Llist_new has expected1");
  TEST_ASSERT_(newllist->next == added2, "after delete Llist_new has added2");
  TEST_ASSERT_(newllist->next->payload == expected2, "after delete Llist_new has expected2");
  TEST_ASSERT_(newllist->next->back == added1, "after delete Llist_new has added1");
  TEST_ASSERT_(newllist->next->next == NULL, "after delete Llist_new has no 3rd item");

  TEST_ASSERT_(newllist->head == added1, "Added1 head is added1");
  TEST_ASSERT_(newllist->tail == added2, "Added1 tail is added2");
  TEST_ASSERT_(newllist->next == added2, "Added1 next is added2");
  TEST_ASSERT_(newllist->back == NULL, "Added1 back is NULL");

  TEST_ASSERT_(newllist->next->head == added1, "Added2 head is added1");
  TEST_ASSERT_(newllist->next->tail == added2, "Added2 tail is added2");
  TEST_ASSERT_(newllist->next->next == NULL, "Added2 next is NULL");
  TEST_ASSERT_(newllist->next->back == added1, "Added2 back is added1");

  Llist_free(newllist);
}

void test_newemptylist_append_three_items_check_tail_head(void) {
  void *expected1 = (void *)55;
  void *expected2 = (void *)66;
  void *expected3 = (void *)77;
  Llist *newllist = Llist_new_empty();
  TEST_ASSERT_(newllist != NULL, "Llist_new expected to be not NULL");

  TEST_ASSERT_(newllist->tail == newllist, "Llist_new tail is Llist_new");
  TEST_ASSERT_(newllist->head == newllist, "Llist_new head is Llist_new");

  Llist *added1 = Llist_append(newllist, expected1);
  TEST_ASSERT_(newllist->tail == added1, "Llist_new tail is added1");
  TEST_ASSERT_(newllist->head == newllist, "Llist_new head is Llist_new");
  TEST_ASSERT_(added1->tail == added1, "Llist_new tail is added1");
  TEST_ASSERT_(added1->head == newllist, "Llist_new head is Llist_new");

  Llist *added2 = Llist_append(newllist, expected2);
  TEST_ASSERT_(newllist->tail == added2, "Llist_new tail is added2");
  TEST_ASSERT_(newllist->head == newllist, "Llist_new head is newllist");
  TEST_ASSERT_(added2->tail == added2, "Llist_new tail is added2");
  TEST_ASSERT_(added2->head == newllist, "Llist_new head is Llist_new");

  Llist *added3 = Llist_append(newllist, expected3);
  TEST_ASSERT_(newllist->tail == added3, "Llist_new tail is added3");
  TEST_ASSERT_(newllist->head == newllist, "Llist_new head is newllist");
  TEST_ASSERT_(added3->tail == added3, "Llist_new tail is added3");
  TEST_ASSERT_(added3->head == newllist, "Llist_new head is Llist_new");

  TEST_ASSERT_(newllist == added1, "Llist_new has added1");
  TEST_ASSERT_(newllist->next == added2, "Llist_new has added2");
  TEST_ASSERT_(newllist->next->next == added3, "Llist_new has added3");
  TEST_ASSERT_(newllist->next->next->next == NULL, "Llist_new has no 4th item");

  TEST_ASSERT_(newllist->back == NULL, "Llist_new back is NULL");
  TEST_ASSERT_(newllist->next->back == added1, "Llist_new 2nd item has back === 1st item");
  TEST_ASSERT_(newllist->next->next->back == added2, "Llist_new 3rd item has back === 2nd item");

  TEST_ASSERT_(added1->back == NULL, "added1 back is NULL");
  TEST_ASSERT_(added2->back == added1, "added2 back is added1");
  TEST_ASSERT_(added3->back == added2, "added3 back is added2");

  TEST_ASSERT_(newllist->payload == expected1, "Llist_new's 1st item is expected1");
  TEST_ASSERT_(newllist->next->payload == expected2, "Llist_new's 2nd item is expected2");
  TEST_ASSERT_(newllist->next->next->payload == expected3, "Llist_new's 3rd item is expected3");

  Llist_free(newllist);
}

TEST_LIST = {
  {"Llist_new_empty() returns an empty list", test_newemptyllist},
  {"Llist_new() returns a list", test_newllist},
  {"Llist_new_empty() append one item", test_newemptyllist_append_one_item},
  {"Llist_new_empty() append two items", test_newemptyllist_append_two_items},
  {"Llist_new_empty() append two items, second item added from the head", test_newemptyllist_append_from_head_append_two_items},
  {"Llist_new_empty() append three items", test_newemptyllist_append_three_items},
  {"Llist_new_empty() append three items, append then from the head", test_newemptyllist_append_from_head_append_three_items},
  {"NewLList() delete first item", test_newemptylist_append_del_item},
  {"Llist_new() append three elements, delete first item", test_newemptylist_append_three_items_del_first_item},
  {"Llist_new() append three elements, delete item in the middle", test_newemptylist_append_three_items_del_item_in_the_middle},
  {"Llist_new() append three elements, delete last item", test_newemptylist_append_three_items_del_last_item},
  {"Llist() append three elements, check tail and head", test_newemptylist_append_three_items_check_tail_head},
  {0}
};
