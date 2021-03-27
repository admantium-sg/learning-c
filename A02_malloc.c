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
#include <string.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {
  char* msg1 = malloc(8);
  char* msg2 = malloc(6);

  printf("Msg1 pointer adrs : %p\n", msg1);
  printf("Msg2 pointer adrs : %p\n", msg2);

  strcpy(msg1, "Tomato");
  strcpy(msg2, "Salad");

  printf("Msg1=%s\n", msg1); 
  printf("Msg2=%s\n", msg2);

  printf("Realloc msg1 to 25 bytes\n");

  realloc(msg2, 25 * sizeof(char));

  printf("Msg2 pointer adrs : %p\n", msg2);
  printf("Msg2=%s\n", msg2); 
  
  strcpy(msg2, "Garlic Sauce with Onions and Paprika");
  printf("Msg2=%s\n", msg2);  // overflows itself
  printf("Msg1=%s\n", msg1); // no overflow to msg1

  free(msg1); //delete heap memory
  free(msg2);

  printf("\nGoodbye!\n");
}