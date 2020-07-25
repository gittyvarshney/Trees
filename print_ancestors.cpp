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


void pre_order(Tree*& temp)
{
  if(temp != NULL)
  {
    cout << temp->data << " ";
    pre_order(temp->left);
    pre_order(temp->right);
  }
}


bool get_ancestors_utility(Tree*&temp, int target)
{
  if(temp== NULL)
  {
    return false;
  }

  if(target>temp->data)
  {
    if(get_ancestors_utility(temp->right,target))
    {
      cout << " -> " <<  temp->data;
      return true;
    }
  }
  else if(target < temp->data)
  {
    if(get_ancestors_utility(temp->left,target))
    {
      cout << " -> " << temp->data;
      return true;
    }
  }
  else
  {
    cout << temp->data;
    return true;
  }
  
}

bool get_ancestors(Tree*&temp, int target)
{
  cout << "\n";
  if(temp == NULL)
  {
    return false;
  }

  if(temp->data < target)
  {
    if(get_ancestors_utility(temp->right,target))
    {
      cout << " -> " << temp->data;
      return true;
    }
    else
    {
      return false;
    }
  }
  else if(temp->data > target)
  {
    if(get_ancestors_utility(temp->left,target))
    {
      cout << " -> " << temp->data;
      return true;
    }
    else
    {
      return false;
    }
  }
  return false;
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
  cout << "\nprinting in  pre Order: ";
  pre_order(root);
  if(!get_ancestors(root,11))
  {
    cout << "No ancestors found \n";
  }
}
