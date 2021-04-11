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

char msg[] = "BSD 3-Clause License \
\
Copyright (c) 2021, Sebastian Günther\
All rights reserved.\
\
Redistribution and use in source and binary forms, with or without\
modification, are permitted provided that the following conditions are met.";

int main(int argc, char *argv[])
{
  FILE *fp;

  if (!(fp = fopen("LICENSE.tmp", "w"))) {
    perror("File not found");
  }

  fputs(msg, fp);

  fclose(fp);
}