/*
 * Copyright (c) 2021 Sebastian Günther 
 * 
 * E-Mail: devcon@admantium.com
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdio.h>

int main(int argc, char* argv[]) {
  char c = 'X';
  char s_1[] = "Hello";
  char s_2[] = {'H', 'e', 'l', 'l', 'o', '\0'}; //C strings are null-terminated

  _Bool b = 1;

  printf("Char c %c\n", c);
  printf("Char[] %s\n",s_1);
  printf("Char[] %s\n",s_2);
  
  printf("Bool b %d\n", b);

  printf("\nGoodbye!\n");
}