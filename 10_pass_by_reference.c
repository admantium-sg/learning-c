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

int* inc(int* i) {
  return (++(*i));
}

int main(int argc, char* argv[]) {
  int i = 42;
  int* i_ptr = &i;

  printf("int i is %d\n", (*i_ptr));

  int** i_ptr2 = inc(i_ptr);
 
  printf("int i is %d\n", i);
  printf("int i is %d\n", *i_ptr);
  printf("int i is %d\n", i_ptr2);

  printf("\nGoodbye!\n");
}