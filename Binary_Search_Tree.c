
#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *Left;
  struct Node *Right;
};

struct Node *createNode(int data)
{
  struct Node *newnode;
  newnode = (struct Node *)malloc(sizeof(struct Node));

  newnode->data = data;
  newnode->Left = NULL;
  newnode->Right = NULL;

  return newnode;
}

struct Node *insert(struct Node *root, int data)
{
  if (root == NULL)
  {
    root = createNode(data);
    return root;
  }
  else if (data < root->data)
  {
    root->Left = insert(root->Left, data);
  }
  else
  {
    root->Right = insert(root->Right, data);
  }

  return root;
}

void inorder(struct Node *root)
{
  if (root != NULL)
  {
    inorder(root->Left);
    printf("%d ", root->data);
    inorder(root->Right);
  }
}

int main()
{
  struct Node *root = NULL;

  root = insert(root, 10);
  root = insert(root, 15);

  inorder(root);

  return 0;
}
