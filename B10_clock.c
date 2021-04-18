/* 
* ---------------------------------------
* Copyright (c) Sebastian Günther 2021  |
*                                       |    
* devcon@admantium.com                  |    
*                                       | 
* SPDX-License-Identifier: BSD-3-Clause | 
* ---------------------------------------
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

void print_n(int max) {
  for(int i = 0; i < max; i++) {
    printf("%d\n", i);
  }
}

int main(int argc, char *argv[]) {
  clock_t start = clock();  
  print_n(100000);
  clock_t end = clock();
  double duration = (double)(end - start) / CLOCKS_PER_SEC;
  
  printf("Elapsed Time: %.2f sec\n", duration);
  
  printf("Goodbye\n");
}