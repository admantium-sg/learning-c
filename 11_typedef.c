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

typedef char STRING[];

int main(int argc, char* argv[]) {
  STRING s = {'I', '`', 'm', ' ', 0x21, '\0'};

  printf("STRING is %s\n", s);

  printf("\nGoodbye!\n");
}