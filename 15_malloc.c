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
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
  int* dynamic_memory = malloc(sizeof(int) * 5); 

  if (dynamic_memory == NULL) {
    printf("ERROR! Could not allocate memory");
    return -1;
  }

  memset(dynamic_memory, 0x1, sizeof(int) * 5);

  printf("Dynamic memory contains %d", dynamic_memory[1]);

  if(dynamic_memory) {
    free(dynamic_memory);
    dynamic_memory = NULL;
  }

  printf("\nGoodbye!\n");
}