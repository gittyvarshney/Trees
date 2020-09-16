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


int tilt(Tree*& temp,int& sum)
{
  if(temp == NULL)
  {
    return 0;
  }
  int a,b;
  a = tilt(temp->left,sum);
  b = tilt(temp->right,sum);
  sum+= abs(a-b);
  //cout << sum << "\n";
  return (a+b+temp->data);
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
  root = create_node(4);
  //Sub tree left
  root->left = create_node(2);
  root->left->left = create_node(3);
  root->left->right = create_node(5);
  //Sub tree right
  root->right = create_node(9);
  root->right->right = create_node(7);
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
  int sum=0;
  tilt(root,sum);
  cout << "tilt is: " << sum << "\n";
}
