#include<bits/stdc++.h>
using namespace std;
//Implementation of Delete a node in a binary Tree
//For deleting a node with no left child just replace the
//node pointer to the right child vice versa
//when node have both the childs fing the minimum value right
//child and replace it with the value of current node with is
//to be deleted and then delete the min_value node which is always
//be a leaf node

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

void in_order(Tree* temp)
{
  if(temp != NULL)
  {
    in_order(temp->left);
    cout << temp->data << " ";
    in_order(temp->right);
  }
}

int inorder_successor(Tree* temp)
{ //caution when using temp = temp->left never use *& has the
  //original vector value gets changes
  while(temp->left != NULL)
  {
    temp = temp->left;
  }
  return temp->data;
}

Tree* delete_node(Tree*& temp,int val)
{
  if(temp== NULL)
  {
    cout << "No node to delete \n";
    return NULL;
  }

  if(val > temp->data)
  {
    temp->right = delete_node(temp->right,val);
  }
  else if(val < temp->data)
  {
    temp->left = delete_node(temp->left,val);
  }
  else
  {
    cout << "val is: " << val << "\n";
    if(temp->left == NULL)
    {
      free(temp);
      return temp->right;
    }
    else if(temp->right == NULL)
    {
      free(temp);
      return temp->left;
    }
    else
    {
      int min_val = inorder_successor(temp->right);
      cout << min_val << "\n";
      temp->data = min_val;
      temp->right = delete_node(temp->right,min_val);
    }
  }
  return temp;
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
  cout << "printing in  Inorder Order: ";
  in_order(root);
  cout << "\n";
  delete_node(root,7);
  cout << "printing in  Inorder Order: ";
  in_order(root);

}
