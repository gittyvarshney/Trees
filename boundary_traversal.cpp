#include<bits/stdc++.h>
using namespace std;
//Boundary Traversal in Binary Tree simple all you have to do is
//first print the root
//print the left part of root till leaf node is not reached
//print the leaves
//print the right part of root till leaf node is not reached

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


void in_order(Tree*& temp)
{
  if(temp != NULL)
  {
    in_order(temp->left);
    cout << temp->data << " ";
    in_order(temp->right);
  }
}

void print_left_side(Tree*& temp)
{
  if(temp == NULL)
  {
    return;
  }

  if(temp->left != NULL)
  {
    cout << temp->data << " ";
    print_left_side(temp->left);
  }
  else if(temp->right != NULL)
  {
    cout << temp->data << " ";
    print_left_side(temp->right);
  }


}

void print_right_side(Tree*& temp)
{
  if(temp == NULL)
  {
    return;
  }

  if(temp->right != NULL)
  {
    cout << temp->data << " ";
    print_left_side(temp->right);
  }
  else if(temp->left != NULL)
  {
    cout << temp->data << " ";
    print_left_side(temp->left);
  }

}

void print_leaves(Tree*& temp)
{
  if(temp== NULL)
  {
    return;
  }

  if(temp->left != NULL)
  {
    print_leaves(temp->left);
  }

  if(temp->right != NULL)
  {
    print_leaves(temp->right);
  }

  if(temp->left == NULL && temp->right == NULL)
  {
    cout << temp->data << " ";
  }

}

void boundary_traversal(Tree*& temp)
{
  if(temp == NULL)
  {
    return;
  }
  cout << temp->data << " ";
  print_left_side(temp->left);
  print_leaves(temp);
  print_right_side(temp->right);

}

int main()
{
  Tree* root = NULL;
  //Simple binary tree creation
  root = create_node(20);
  //Sub tree left
  root->left = create_node(8);
  root->left->left = create_node(4);
  root->left->right = create_node(12);
  root->left->right->left = create_node(10);
  root->left->right->right = create_node(14);
  //Sub tree right
  root->right = create_node(22);
  root->right->right = create_node(25);

  in_order(root);
  cout << "\n";
  boundary_traversal(root);
}
