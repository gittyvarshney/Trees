#include<bits/stdc++.h>
using namespace std;
//for top view just print the first hashes of vertical traversal (inorder)
//for bottom view just print the last hashes of vertical traversal (inorder)
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

void in_order(Tree*& temp,int& prev,int& k,int& ans)
{
  if(temp != NULL)
  {
    if(k!=-1)
    {
      in_order(temp->left,prev,k,ans);
    }
    if(temp->data != prev && k!=-1)
    {
      if(k==0)
      {
        k--;
        ans = temp->data;
      }
      else
      {
        k--;
        prev = temp->data;
      }
    }
    if(k!=-1)
    {
    in_order(temp->right,prev,k,ans);
    }
  }
}

int main()
{
  Tree* root = NULL;
  /*
  create_node(root, 8);
  create_node(root, 4);
  create_node(root, 12);
  create_node(root, 2);
  create_node(root, 6);
  create_node(root, 10);
  create_node(root, 14);
  create_node(root, 1);
  create_node(root, 3);
  create_node(root, 5);
  create_node(root, 7);
  create_node(root, 9);
  create_node(root, 11);
  create_node(root, 13);
  create_node(root, 15);
  */
  create_node(root,20);
  create_node(root,3);
  create_node(root,4);
  create_node(root,10);
  create_node(root,3);
  create_node(root,3);
  create_node(root,2);
  int max = INT_MAX;
  int k = 4;
  k--;
  int ans=-1;
  in_order(root,max,k,ans);
  cout << ans;
}
