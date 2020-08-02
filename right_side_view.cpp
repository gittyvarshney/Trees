#include<bits/stdc++.h>
using namespace std;
//for right side view you have to do just level order traversal
//you have to just print last member of the same level for this
//you have to take previous level into consideration and store the
//previous node if level changes just print that previous member
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
  int prev_curr=1;
  int previous;
  int n=0;
  while(!q.empty())
  {
    if(q.front().second!= prev_curr)
    {
      cout << previous << " ";
      n++;
      prev_curr = q.front().second;
    }
    previous = q.front().first->data;
    if(q.front().first->left != NULL)
    {
      q.push(make_pair(q.front().first->left,q.front().second+1));
    }
    if(q.front().first->right != NULL)
    {
      q.push(make_pair(q.front().first->right,q.front().second+1));
    }
    q.pop();
  }
  if(n<prev_curr) //for the last remaining node of particular level
  {
    cout << previous << " ";
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
  cout << "Printing in level Order: ";
  level_order(root);
}
