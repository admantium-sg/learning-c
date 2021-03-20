/*
 * Copyright (c) 2021 Sebastian Günther 
 * 
 * E-Mail: devcon@admantium.com
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdio.h>


char* intToBinary(int i, char* buffer) {
  int base[] = {8,4,2,1};
  for (int j = 0; j < 4; j++) {
    if((i - base[j] >= 0)) {
      buffer[j] = '1';
      i -= base[j]; 
    } else {
      buffer[j] = '0';
    }
  }
  return buffer;
}

void resetBuffer(char* buffer, size_t size) {
  for (int i = 0; i<size; i++) {
    buffer[i] = '0';
  }
}

int main(int argc, char* argv[]) {
  int i = 10, j = 1;

  char binary[4] = {0};

  printf("Binary 10 = %s \n", intToBinary(10, &binary)); resetBuffer(&binary,4);
  printf("Binary 11 = %s \n", intToBinary(11, &binary)); resetBuffer(&binary, 4);
  printf("Bitwise & / 10 & 11 = %s \n", intToBinary(10 & 11, &binary)); resetBuffer(&binary, 4);
  printf("Bitwise | / 10 | 11 = %s \n", intToBinary(10 | 11, &binary)); resetBuffer(&binary, 4);
  printf("Bitwise ^ / 10 ^ 11 = %s \n", intToBinary(10 ^ 11, &binary)); resetBuffer(&binary, 4);
  printf("Bitwise << / 10 << 11 = %s \n", intToBinary(10 << 1, &binary)); resetBuffer(&binary, 4);
  printf("Bitwise >> / 10 >> 11 = %s \n", intToBinary(10 >> 1, &binary)); resetBuffer(&binary, 4);
  printf("Bitwise ~ / ~10 = %s \n", intToBinary(~10, &binary)); resetBuffer(&binary, 4);
}