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

void reverse(char msg[], size_t size) {
  printf("Input: '%s' ^ size %d \n", msg, (int) size);
  char *end_ptr = msg + size - 2;
  char *start_ptr = msg;

  char temp;

  int i = 0;
  while(i < size/2) {
    temp = *start_ptr;
    *start_ptr = *end_ptr;
    *end_ptr = temp;
    start_ptr++;
    end_ptr--;
    i++;
  }

  printf("Reversed: '%s'\n", msg);
}

static void test(void **state)
{
  char msg[] = "Will be reversed";
  reverse(msg, sizeof(msg));
  assert_memory_equal(msg, &"desrever eb lliW", sizeof(msg));
}

int main(int argc, char *argv[])
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}