#include<bits/stdc++.h>
using namespace std;
//For getting average of levels you have to store another integer in queue
//along with the pointer to store the current level and do sum till the level
//is same and if different just print the sum divided by n of same levels
//and reset the current level and n
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

void level_order(Tree*& root)
{
  Tree* temp = root;
  if(temp == NULL)
  {
    return;
  }
  queue<pair<Tree*,int>> q;
  q.push(make_pair(temp,1));
  int curr=1;
  double sum=0;
  int n=0;
  while(!q.empty())
  {
    if(q.front().second == curr)
    {
      sum+= q.front().first->data;
      n++;
    }
    else
    {
      curr = q.front().second;
      cout << sum/n << " ";
      sum=0;
      n=0;
      sum+= q.front().first->data;
      n++;
    }
    //cout << q.front().first->data << " ";
    if(q.front().first->left != NULL)
    {
      q.push(make_pair(q.front().first->left,curr+1));
    }
    if(q.front().first->right != NULL)
    {
      q.push(make_pair(q.front().first->right,curr+1));
    }
    q.pop();
  }
  cout << sum/n;
}

int main()
{
  Tree* root = NULL;
  create_node(root, 7);
  create_node(root, 9);
  create_node(root, 5);
  create_node(root, 11);
  create_node(root, 8);
  create_node(root, 6);
  create_node(root, 4);
  cout << "Printing in level Order: ";
  level_order(root);
}
