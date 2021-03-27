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
#include <errno.h>

int main(int argc, char* argv[]) {

  FILE* f_ptr = fopen("/root/out.log", "w+");
  
  if (f_ptr == NULL) {
    perror("ERROR! Could not create file");
    return errno;
  }

  char buffer[1000];

  printf("Enter any text, terminated by newline\n");
  printf("$> ");

  fgets(buffer, 1000, stdin);

  printf("You entered: %s\n\n", buffer);
  printf("Writing to file \"out.log\" ");

  fprintf(f_ptr, "%s:%s\n\n%s", __DATE__, __TIME__, buffer);
  fclose(f_ptr);

  printf("\n\nGoodbye\n");
}