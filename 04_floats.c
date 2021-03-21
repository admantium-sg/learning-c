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
  float f, f_exp, f_hex; //precision: 7 digits
  double d; //precision: 15 digits
  long double ld; //precision: 15 digits

  f = 427135.1451;
  f_exp = 42e5;
  f_hex = 0xc0ffe;
  d = 325.35125326436347347474326;
  ld = 325.3512532643634734747432635125326436347347474326L;

  printf("Float f %f\n", f);
  printf("Float f_exp %f\n", f_exp);
  printf("Float f_hex %f\n", f_hex);
  printf("Double d %f\n", d);
  printf("Double ld %Ld\n", ld);

  printf("\nGoodbye!\n");
}