/* 
* ---------------------------------------
* Copyright (c) Sebastian Günther 2021  |
*                                       |    
* devcon@admantium.com                  |    
*                                       | 
* SPDX-License-Identifier: BSD-3-Clause | 
* ---------------------------------------
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  FILE *fp;
  char buffer[200];

  if (!(fp = fopen("LICENSE", "r"))) {
    perror("File not found");
  }

  while(!feof(fp)) {
    fgets(buffer, 100, fp);
    printf("%s", buffer);
    sleep(1);
  }
}