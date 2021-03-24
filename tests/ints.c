/*
 * Copyright (c) 2021 Sebastian Günther 
 * 
 * E-Mail: devcon@admantium.com
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdio.h>
#include <stdint.h>

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

