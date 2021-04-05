/* 
* ---------------------------------------
* Copyright (c) Sebastian Günther 2021  |
*                                       |    
* devcon@admantium.com                  |    
*                                       | 
* SPDX-License-Identifier: BSD-3-Clause | 
* ---------------------------------------
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

typedef struct Book
{
  int id;
  char *title;
  bool borrowed;
  void (*set_borrowed)(struct Book *, bool);
} Book;

void _set_borrowed(struct Book *b, bool status)
{
  b->borrowed = status;
}

Book _book_factory(int id, char *title)
{
  Book b;

  b.id = id;
  b.title = title;
  b.borrowed = false;

  b.set_borrowed = _set_borrowed;

  return b;
}

Book _book_factory2(int id, char *title)
{
  return (Book){.id = id, .title = title};

  // b.id = id;
  // memcpy(b.title, title, 30);
  // b.borrowed = false;

  // b.set_borrowed = _set_borrowed;

  // return b;
}

static void test_book_factory(void **state)
{
  Book b = _book_factory(42, "Programming C");

  assert_int_equal(42, b.id);
  assert_memory_equal(&b.title, &"Programming C", 30);
  assert_false(b.borrowed);

  b.set_borrowed(&b, true);
  assert_true(b.borrowed);

  Book b2 = _book_factory2(42, "Programming C");
  assert_int_equal(42, b2.id);
  printf("Title 2 %s", b2.title);
  // assert_memory_equal(&b2.title, &"Programming C", 30);
}

int main(int argc, char *argv[])
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_book_factory),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}