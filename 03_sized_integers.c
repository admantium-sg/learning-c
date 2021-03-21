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
#include <stdint.h>

int main(int argc, char* argv[]) {
  int8_t i8;
  int16_t i16;
  int32_t i32;
  int64_t i64;
  
  printf("Max size of i8 %zu bytes\n", sizeof(i8));
  printf("Max size of i16 %zu bytes\n", sizeof(i16));
  printf("Max size of i32 %zu bytes\n", sizeof(i32));
  printf("Max size of i64 %zu bytes\n", sizeof(i64));
}