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
  FILE* f_ptr = fopen("12_structs.c", "r");
  char buffer[2000];

  fread(buffer, 2000, 1, f_ptr); 

  printf("Content of file\n\n");
  printf("%s", buffer);
  printf("\n\nGoodbye\n");
}