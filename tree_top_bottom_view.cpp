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

void top_view(Tree*& root,int dist,map<int,vector<int>>& vo)
{
  if(root == NULL)
  {
    return;
  }
  queue<pair<Tree*,int>> q;
  q.push(make_pair(root,dist));
  while(!q.empty())
  {
    vo[q.front().second].emplace_back(q.front().first->data);
    if(q.front().first->left != NULL)
    {
      q.push(make_pair(q.front().first->left,q.front().second-1));
    }
    if(q.front().first->right != NULL)
    {
      q.push(make_pair(q.front().first->right,q.front().second+1));
    }
    q.pop();
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

  map<int,vector<int>>vo;
  cout << "Printing the top View: ";
  top_view(root,0,vo);
  for(auto i: vo)
  {
    for(auto j: i.second)
    {
      cout << j << " ";
      break;
    }
  }
  //bottom_view
  cout << "\n";
  cout << "Printing the bottom View: ";
  map<int,vector<int>>::reverse_iterator r;
  int temp;
  for(auto i: vo)
  {
    for(auto j : i.second)
    {
      temp = j;
    }
    cout << temp << " ";
  }
}
