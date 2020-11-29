#include <stdio.h>
#include "myfile.h"
#include "myfile.c"

int main()
{
  int r = add_example(2, 2);
  printf("hello, world!\n");
  printf("r = %d\n", r);

  return 0;
}