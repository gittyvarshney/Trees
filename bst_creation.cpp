#include<bits/stdc++.h>
using namespace std;
//implementation of binary tree

class Tree
{
public:
  int data;
  Tree* left;
  Tree* right;
};

void insert_bst(Tree*& temp,Tree*& insert_node)
{
  if(temp->data < insert_node->data)
  {
    if(temp->right == NULL)
    {
      temp->right = insert_node;
      return;
    }
    else
    {
      return insert_bst(temp->right,insert_node);
    }
  }
  else
  {
    if(temp->left == NULL)
    {
      temp->left = insert_node;
      return;
    }
    else
    {
      return insert_bst(temp->left,insert_node);
    }
  }
}

void create_node(Tree*& root,int n)
{
  Tree* temp = root;
  Tree* new_node = new Tree();
  new_node->data = n;
  new_node->left = NULL;
  new_node->right = NULL;

  if(temp == NULL)
  {
    root = new_node;
  }
  else //insert in bst
  {
    insert_bst(temp,new_node);
  }
}

void in_order(Tree*& temp)
{
  if(temp != NULL)
  {
    in_order(temp->left);
    cout << temp->data << " ";
    in_order(temp->right);
  }
}

void pre_order(Tree*& temp)
{
  if(temp != NULL)
  {
    cout << temp->data << " ";
    pre_order(temp->left);
    pre_order(temp->right);
  }
}

void post_order(Tree*& temp)
{
  if(temp != NULL)
  {
    post_order(temp->left);
    post_order(temp->right);
    cout << temp->data << " ";
  }
}

int main()
{
  Tree* root = NULL;
  create_node(root, 7);
  create_node(root, 9);
  create_node(root, 5);
  create_node(root, 10);
  create_node(root, 8);
  create_node(root, 6);
  create_node(root, 4);
  cout << "\nprinting in  Inorder Order: ";
  in_order(root);
  cout << "\nprinting in  pre Order: ";
  pre_order(root);
  cout << "\nprinting in  post Order: ";
  post_order(root);
}
