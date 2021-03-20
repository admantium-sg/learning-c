/*
 * Copyright (c) 2021 Sebastian Günther 
 * 
 * E-Mail: devcon@admantium.com
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
  char s_1[] = "Hello";
  char s_2[] = {'H', 'e', 'l', 'l', 'o', '\0'}; //C strings are null-terminated
  char* s_3 = "Hello"; //static string, pointer value can not be changed

  printf("String s_1 %s\n", s_1);
  printf("String s_2 %s\n", s_2);
  printf("String s_3 %s\n", s_3);

  // *(s_3 + 0) = 'Y'; Error: Segmentation fault
  
  // Use asci values in String
  char* s_4 = "\x50\x69\x63\x6f";
  printf("String s_3 %s\n", s_4);

  char prefix[] = "Blackguard";
  char suffix[] = "Protects";

  size_t len_p = strlen(prefix), len_s = strlen(suffix);
  char word[len_p]; //contains two null symbols

  strcpy(word, strcat(prefix, suffix));

  printf("WORD is %s", word);

  printf("\nGoodbye!\n");
}