
#include "acutest.h"
#include "myfile.c"

void test_add(void) {
  TEST_ASSERT_(add_example(2, 2) == (2 + 2), "add_example(%d,%d)==%d", 2, 2, (2+2));
}

TEST_LIST = {
  {"int add(int, int)", test_add},
  {0}
};