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

int *insert_into_array(int *arr, size_t size, int val, int position)
{
  if (position > size)
    return NULL;

  int *src_cpy = malloc(sizeof(int) * size + 1);
  bool matched = false;
  for (int i = 0; i < size + 1; i++)
  {
    if (i == position)
    {
      *(src_cpy + i) = val;
      matched = true;
    }
    else if (!matched)
    {
      *(src_cpy + i) = *(arr + i);
    }
    else if (matched)
    {
      *(src_cpy + i) = *(arr + i - 1);
    }
  }
  return src_cpy;
}

static void test_insert_into_array(void **state)
{
  int arr[] = {10, 20, 30, 43};

  for (int i = 0; i < 4; i++)
  {
    printf("ARR [%d]=%d\n", i, *(arr + i));
  }

  printf("Insert into array ...\n");

  int *res_ptr = insert_into_array(arr, 4, 123, 2);

  int res_expt[] = {10, 20, 123, 30, 43};

  for (int i = 0; i < 5; i++)
  {
    printf("RES [%d]=%d\n", i, *(res_ptr + i));
  }

  assert_memory_equal(res_ptr, &res_expt, sizeof(res_expt));
}

int main(int argc, char *argv[])
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_insert_into_array),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}