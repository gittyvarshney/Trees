#include<bits/stdc++.h>
using namespace std;
//inorder traversal traverse nodes in increasing Order
//if can also able to print nodes in decreasing Order hence question solved

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

void bst_to_greater_sum(Tree*& root,int& sum)
{
  if(root==NULL)
  {
    return;
  }
  bst_to_greater_sum(root->right,sum);
  int temp = root->data;
  root->data = sum;
  sum += temp;
  bst_to_greater_sum(root->left,sum);
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

int main()
{
  Tree* root = NULL;
  create_node(root, 11);
  create_node(root, 2);
  create_node(root, 29);
  create_node(root, 40);
  create_node(root, 15);
  create_node(root, 7);
  create_node(root, 1);
  create_node(root, 35);
  cout << "Counting nodes in Bst in Interval : ";
  int sum=0;
  bst_to_greater_sum(root,sum);
  pre_order(root);
}
