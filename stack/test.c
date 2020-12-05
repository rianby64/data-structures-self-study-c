
#include <stdbool.h>
#include "acutest.h"
#include "stack.h"

void test_new_empty_stack(void);
void test_new_empty_stack_push_pop(void);
void test_new_empty_stack_push_three_times_pop(void);

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

void test_new_empty_stack_push_three_times_pop(void) {
  void *expected1 = (void *)55;
  void *expected2 = (void *)66;
  void *expected3 = (void *)77;
  Stack *stack = Stack_new();

  TEST_ASSERT_(stack != NULL, "New empty stack expected to be not NULL");

  Stack_push(stack, expected1);
  Stack_push(stack, expected2);
  Stack_push(stack, expected3);
  void *actual3 = Stack_pop(stack);
  void *actual2 = Stack_pop(stack);
  void *actual1 = Stack_pop(stack);

  Stack_pop(stack);
  Stack_pop(stack);
  Stack_push(stack, expected3);
  Stack_pop(stack);
  Stack_pop(stack);

  TEST_ASSERT_(actual3 == expected3, "Pop from stack === expected3");
  TEST_ASSERT_(actual2 == expected2, "Pop from stack === expected2");
  TEST_ASSERT_(actual1 == expected1, "Pop from stack === expected1");
  TEST_ASSERT_(Stack_pop(stack) == NULL, "Pop from empty stack === NULL");

  Stack_free(stack);
}

TEST_LIST = {
  {"stack_new_empty() returns an empty list", test_new_empty_stack},
  {"stack push then pop", test_new_empty_stack_push_pop},
  {"stack push three times then pop until NULL", test_new_empty_stack_push_three_times_pop},
  {0}
};
