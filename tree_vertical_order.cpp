#include<bits/stdc++.h>
using namespace std;
//fro vertical order traversal you just have to use hashmap to store
//the vertical distances of each node and printing them
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

void vertical_order(Tree*& root,int dist,map<int,vector<int>>& vo)
{
  if(root != NULL)
  {
    vertical_order(root->left,dist-1,vo);
    vo[dist].emplace_back(root->data);
    vertical_order(root->right,dist+1,vo);
  }
}

int main()
{
  Tree* root = NULL;
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
  cout << "Printing in Vertical Order: \n";
  map<int,vector<int>>vo;
  vertical_order(root,0,vo);
  for(auto i: vo)
  {
    for(auto j: i.second)
    {
      cout << j << " ";
    }
    cout << "\n";
  }
}
