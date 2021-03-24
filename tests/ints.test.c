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
int* numbers[100];
int current_index = 0;

void add(int n) {
  if (current_index == max) return;
  *numbers[current_index] = n;
}

void incr(int i) {
  if (current_index < i) return;
  *numbers[current_index] += 1;
}

int get(int i) {
  if (i > max) return 0;
  return *numbers[i];
}

static void test1(void **state) {
  assert_int_equal(0, 0);
}

int main(int argc, char* argv[]) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test1),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}