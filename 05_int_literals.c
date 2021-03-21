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
  int i = 10;
  long int li = 100L;
  unsigned int ui = 35531U;

  printf("Int i %d\n", i);
  printf("Int li %Ld\n", li);
  printf("Int ui %d\n", ui);
  
  printf("Int ui Hex %X\n", ui);
  printf("Int ui Oct %o\n", ui);

  printf("\nGoodbye!\n");
}