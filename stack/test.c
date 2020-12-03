
#include <stdbool.h>
#include "acutest.h"
#include "stack.h"

void test_new_empty_stack(void);

void test_new_empty_stack(void) {

  Stack *stack = Stack_new();

  TEST_ASSERT_(stack != NULL, "New empty stack expected to be not NULL");

  Stack_free(stack);
}

TEST_LIST = {
  {"_stack_new_empty() returns an empty list", test_new_empty_stack},
  {0}
};
