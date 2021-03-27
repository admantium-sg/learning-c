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
  printf("Enter a number, an operator, and a number\n");

  int i, j, res;
  char op;

  printf("First number\n");
  scanf("%d", &i);
  
  printf("Operator\n");
  scanf(" %c", &op);

  printf("Second number\n");
  scanf("%d", &j);

  switch (op) {
    case 0x2B:  // +
      res = i + j;
      break;
    case 0x2D:  // -
      res = i - j;
      break;
    case 0x2A:  // *
      res = i * j;
      break;
    case 0x2F:  // /
      res = i / j;
      break;
    default:
      res = i+j;
      break;
  };

  printf("Goodbye\n");
  printf("You entered %d%c%d=%d\n", i, op, j, res);
  printf("Goodbye\n");
}