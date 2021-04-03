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
  char title[30];
  bool borrowed;
  void (*set_borrowed)(struct Book *, bool);
} Book;

void _set_borrowed(struct Book *b, bool status)
{
  b->borrowed = status;
}

Book _book_factory(int id, char title[])
{
  Book b;

  b.id = id;
  memcpy(b.title, title, 30);
  b.borrowed = false;

  b.set_borrowed = _set_borrowed;

  return b;
}

static void test_book_factory(void **state)
{
  Book b = _book_factory(42, "Programming C");

  assert_int_equal(42, b.id);
  assert_memory_equal(&b.title, &"Programming C", 30);
  assert_false(b.borrowed);

  b.set_borrowed(&b, true);
  assert_true(b.borrowed);
}

int main(int argc, char *argv[])
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_book_factory),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}