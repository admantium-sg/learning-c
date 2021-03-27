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

typedef struct book book;

struct book {
  char name[10];
  int pages;
};

void setPages(book* b, int p) {
  (*b).pages = p;
}

int main(int argc, char* argv[]) {
  book b1 = {"C Syntax", 160};

  printf("Book1:  title '%s' | pages: %d\n", b1.name, b1.pages);
  
  setPages(&b1, 200);
  
  printf("Book1:  title '%s' | pages: %d\n", b1.name, b1.pages);

  printf("\nGoodbye!\n");
}