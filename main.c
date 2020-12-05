
#include <stdlib.h>

typedef struct object {
  int x;
  int y;
  struct object *tree;
} Object;

Object *Object_new() {
  Object *newObj = malloc(sizeof(Object));

  newObj->tree = newObj;
  return newObj;
}

void Object_free(Object *o) {
  /*
  // CASE 1
  Object *m = o->tree;
  free(m);
  m = NULL;
  */

  /*
  // CASE 2
  free(o->tree);
  o->tree = NULL;
  */

  /*
  // CASE 3
  Object *m = o;
  free(m);
  m = NULL;
  */

  // CASE 4
  free(o);
  o = NULL;
}

int main() {
  Object *a = Object_new();

  Object_free(a->tree);
  Object_free(a);
}
