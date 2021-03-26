/*
 * Copyright (c) 2021 Sebastian Günther 
 * 
 * E-Mail: devcon@admantium.com
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdio.h>

int main(int argc, char* argv[]) {
  printf("You provided %d arguments:\n", argc + 1 );

  for(int i = 0; i <= argc; i++) {
    printf("arg %d: %s\n" ,i, argv[i] );
  }
}