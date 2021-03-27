/* 
* ---------------------------------------
* Copyright (c) Sebastian Günther 2021  |
*                                       |    
* devcon@admantium.com                  |    
*                                       | 
* SPDX-License-Identifier: BSD-3-Clause | 
* ---------------------------------------
*/
#include <stdio.h>
#include <string.h>

void printThemAll(int n, ...) {
  va_list var_args;
  printf("Number of args: %d", n);

  va_start(var_args, n);
  int i = 0;
  
  do {
    printf("ARG %d = %d\n", i, va_arg(var_args, int));
  } while (i++ < n);
}

int main(int argc, char* argv[]) {
  char s[] = "Hello";
  int i = 42;
  double d = 12412.12412;

  printThemAll(3, i, d, s);

  printf("\nGoodbye!\n");
}