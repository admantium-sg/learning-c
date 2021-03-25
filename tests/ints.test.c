/*
 * Copyright (c) 2021 Sebastian Günther 
 * 
 * E-Mail: devcon@admantium.com
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

const size_t max = 100;
int numbers[100] = {0};
int current_index = 0;

void add(int n) {
  if (current_index == max) return;
  numbers[current_index++] = n;
}

void incr(int i) {
  if (current_index < i) return;
  numbers[i] += 1;
}

int get(int i) {
  if (i > max) return 0;
  return numbers[i];
}

static void numbers_is_0_initialized(void **state) {
  assert_int_equal(0, numbers[0]);
}

static void adding_numbers(void **state) {
  add(10);
  add(23);
  add(42);
  assert_int_equal(10, get(0));
  assert_int_equal(23, get(1));
  assert_int_equal(42, get(2));
}

static void incr_numbers(void **state) {
  incr(0);
  incr(0);
  incr(2);
  assert_int_equal(12, get(0));
  assert_int_equal(43, get(2));
}

int main(int argc, char* argv[]) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(numbers_is_0_initialized),
    cmocka_unit_test(adding_numbers),
    cmocka_unit_test(incr_numbers),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}