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

Tree* create_node(int n)
{
  Tree* new_node = new Tree();
  new_node->data = n;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}


void no_sibling(Tree*& temp)
{
  if(temp == NULL)
  {
    return ;
  }
  if(temp->right == NULL && temp->left != NULL )
  {
    cout << temp->left->data << " ";
  }
  else if(temp->right != NULL && temp->left == NULL)
  {
    cout << temp->right->data << " ";
  }
  no_sibling(temp->left);
  no_sibling(temp->right);
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

int main()
{
  Tree* root = NULL;
  //Simple binary tree creation
  root = create_node(1);
  //Sub tree left
  root->left = create_node(2);
  root->left->right = create_node(4);
  //Sub tree right
  root->right = create_node(3);
  root->right->left = create_node(5);
  root->right->left->left = create_node(6);
  /*
  cout << "\nprinting in  Inorder Order: ";
  in_order(root);
  cout << "\nprinting in  pre Order: ";
  pre_order(root);
  cout << "\nprinting in  post Order: ";
  post_order(root);
  */
  in_order(root);
  cout << "\n";
  no_sibling(root);
}
