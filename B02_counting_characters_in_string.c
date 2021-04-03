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
#include <stdbool.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

typedef char string[];

int count_char_in_string(string str, char s_crt, size_t size)
{
  int count = 0;
  for (int i = 0; i < size; i++)
  {
    if (*(str + i) == s_crt)
      count++;
  }
  return count;
}

static void test_counting_characters(void **state)
{
  string headline = "Breaking news in the Andromeda Galaxy";
  assert_int_equal(4, count_char_in_string(headline, 'a', sizeof(headline)));

  string lorem = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis, ultricies nec, pellentesque eu, pretium quis, sem. Nulla consequat massa quis enim. Donec pede justo, fringilla vel, aliquet nec, vulputate eget, arcu. In enim justo, rhoncus ut, imperdiet a, ve";
  assert_int_equal(22, count_char_in_string(lorem, 'a', sizeof(lorem)));
}

int main(int argc, char *argv[])
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_counting_characters),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}