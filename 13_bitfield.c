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

union {
  int val;
  const char single[4];
  const struct { 
    short hi;
    short lo;
  } section;
} bitfield;

int main(int argc, char* argv[]) {
  bitfield.val = 0xc0ffe;

  printf("Bitfield: val %d\n", bitfield.val);
  printf("Bitfield: single[2] %d\n", bitfield.single[1]);
  printf("Bitfield: hi %d\n", bitfield.section.hi);
  printf("Bitfield: lo %d\n", bitfield.section.lo);

  printf("\nGoodbye!\n");
}