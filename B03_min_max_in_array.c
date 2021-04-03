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

int *min_max(int *arr, size_t size)
{
  int val = *(arr + 0);
  int min = val;
  int max = val;

  while ((val = *(arr++)))
  {
    if (val > max)
    {
      max = val;
    }
    if (val < min)
    {
      min = val;
    }
  }

  static int res[2];
  res[0] = min;
  res[1] = max;

  return &res;
}

static void test_min_max(void **state)
{
  int arr[] = {10, 20, 30, 45, 1, 7, 84};

  int *p;
  p = min_max(&arr, sizeof(arr) / sizeof(arr[0]));

  assert_int_equal(1, *p);
  assert_int_equal(84, *(p + 1));
}

int main(int argc, char *argv[])
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_min_max),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}