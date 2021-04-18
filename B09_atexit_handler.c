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

char *msg;

void cleanup() {
  free(msg);
  printf("Cleanup called, have a happy day\n");
}

int main(int argc, char *argv[]) {
  if (atexit(cleanup)) {
    printf("ERROR: Could not register exit function, terminating\n");
    abort();
  }

  msg  = malloc(30 * sizeof(char));

  printf("Please enter a message: \n");
  printf("> ");
  scanf("%s", msg);


  printf("You entered: '%s'\n", msg);
}