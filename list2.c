#include <stdio.h>
#include <stdlib.h>

struct n
{
  int x;
  struct n *next;
};

typedef struct n node;

void handle(node *r)
{
  while (r != NULL)
  {
    printf("%d ", r->x);
    r = r->next;
  }
}

void add(node *r, int x)
{
  while (r->next != NULL)
    r = r->next;
  r->next = (node *)malloc(sizeof(node));
  r->next->x = x;
  r->next->next = NULL;
}

int main()
{
  node *root;
  root = (node *)malloc(sizeof(node));
  root->next = NULL;
  root->x = 500;
  for (int i = 0; i < 5; i++)
  {
    add(root, i * 10);
  }
  handle(root);
}
