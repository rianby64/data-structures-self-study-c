
#include "acutest.h"

#include "llist.h"
#include "llist.c"

void test_add(void) {
  TEST_ASSERT_(add_example(2, 2) == (2 + 2), "add_example(%d,%d)==%d", 2, 2, (2+2));
}

TEST_LIST = {
  {"NewLlist() returns an empty list", test_add},
  {0}
};