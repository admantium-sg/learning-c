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
#include <pthread.h>

void* func(void* msg) {
  printf("In sub, modyfying msg");

  return NULL;
}

int main(int argc, char* argv[]) {
  char msg1[] = {"Hello Main!"};

  pthread_t sub;

  printf("In main? %s\n", msg1);

  pthread_create(&sub, NULL, func, &msg1);

  pthread_join(sub, NULL);

  printf("In main? %s\n", msg1);

  printf("\nGoodbye!\n");
}