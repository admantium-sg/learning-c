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

int main(int argc, char* argv[]) {
  char msg1[8];
  char msg2[6];

  strcpy(msg1, "Tomato");
  strcpy(msg2, "Salad");

  printf("Msg1 pointer adrs : %p\n", msg1);
  printf("Msg2 pointer adrs : %p\n", msg2);

  printf("Msg1=%s\n", msg1); 
  printf("Msg2=%s\n", msg2);

  printf("Now overflowing ...\n");
  strcpy(msg2, "Garlic Sauce with Onions");
  
  printf("Msg2=%s\n", msg2); // longer then allocated 8 byte...
  printf("Msg1=%s\n", msg1); // .. because it overflowed into msg2!


  printf("\nGoodbye!\n");
}