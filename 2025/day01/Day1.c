#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  int value;
  struct Node *next;
  struct Node *prev;
} Node;

int main() {
  Node *head = NULL;
  Node *prev = NULL;

  for (int i = 0; i < 100; i++) {
    Node *n = malloc(sizeof(Node));
    n->value = i;
    n->next = NULL;
    n->prev = prev;

    if (prev != NULL) {
      prev->next = n;
    } else {
      head = n;
    }
    prev = n;
  }

  head->prev = prev;
  prev->next = head;

  Node *ptr = head;
  while (ptr->value != 50)
    ptr = ptr->next;

  int countZero = 0;
  char cmd[20];

  while (scanf("%19s", cmd) == 1) {
    char dir = cmd[0];
    int steps = atoi(cmd + 1);

    for (int i = 0; i < steps; i++) {
      if (dir == 'L') {
        ptr = ptr->prev;
      } else {
        ptr = ptr->next;
      }

      if (ptr->value == 0) {
        countZero++;
      }
    }
  }

  printf("%d\n", countZero);
  return 0;
}
