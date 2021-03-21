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

int main(int argc, char* argv[]) {
  char c = 0;
  int i = 0;
  short s = 0;
  long l = 0;

  printf("Max size of char %zu bytes\n", sizeof(c));
  printf("Max size of int %zu bytes\n", sizeof(i));
  printf("Max size of short %zu bytes\n", sizeof(s));
  printf("Max size of long %zu bytes\n", sizeof(l));
}