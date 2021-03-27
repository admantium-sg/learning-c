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

#pragma "Compiling " __FILE__

int main(int argc, char* argv[]) {
  printf("This programm was compiled %s | %s\n",__DATE__, __TIME__ );
  printf("File Name: %s\n", __FILE__);
  printf("Now in Line %d\n", __LINE__);

  printf("\nGoodbye!\n");
}