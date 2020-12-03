
#include <stdbool.h>
#include "acutest.h"
#include "stack.h"

void test_new_empty_stack(void);
void test_new_empty_stack_push_pop(void);

void test_new_empty_stack(void) {
  Stack *stack = Stack_new();

  TEST_ASSERT_(stack != NULL, "New empty stack expected to be not NULL");

  void *actual = Stack_pop(stack);

  TEST_ASSERT_(actual == NULL, "Pop from empty stack === NULL");

  Stack_free(stack);
}

void test_new_empty_stack_push_pop(void) {
  void *expected = (void *)55;
  Stack *stack = Stack_new();

  TEST_ASSERT_(stack != NULL, "New empty stack expected to be not NULL");

  Stack_push(stack, expected);
  void *actual = Stack_pop(stack);

  TEST_ASSERT_(actual == expected, "Pop from stack === expected");
  TEST_ASSERT_(Stack_pop(stack) == NULL, "Pop from empty stack === NULL");

  Stack_free(stack);
}

TEST_LIST = {
  {"stack_new_empty() returns an empty list", test_new_empty_stack},
  {"stack push then pop", test_new_empty_stack_push_pop},
  {0}
};
