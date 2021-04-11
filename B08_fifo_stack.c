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
#include <stdbool.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

typedef struct Node {
  int value;
  struct Node (*next);
} Node;

void push(struct Node* node);
struct Node* pop();

Node t;
Node *top;

void push(struct Node* node) {
  if (top == NULL) {
    top = node;
    return;
  }

  node->next = top;
  top = node;
}

struct Node* pop() {
  if (top == NULL) {
    return NULL;
  }

  Node *removed_node = top;
  Node *next_top = top->next;
  top = next_top;

  return removed_node;
}

static void test(void **state)
{
  Node n1;
  n1.value = 1;

  Node n2;
  n2.value = 2;

  push(&n1);
  assert_memory_equal(&n1, top, sizeof(Node));

  push(&n2);
  assert_memory_equal(&n2, top, sizeof(Node));

  Node *last;
  last = pop();
  
  assert_memory_equal(&n2, last, sizeof(Node));
  assert_memory_equal(&n1, top, sizeof(Node));
}

int main(int argc, char *argv[])
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}