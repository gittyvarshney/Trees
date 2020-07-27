#include<bits/stdc++.h>
using namespace std;
//given a binary tree you have to find the minimum number of cameras needed
//to cover all the nodes of the tree a camera covers a parent and its
//immediate children

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

void minimum_cameras(Tree*&node, Tree*&parent, int& cameras, set<Tree*>& s)
{
  cout << "tag\n";
  if(node == NULL)
  {
    return;
  }

  if(node->left != NULL)
  {
    minimum_cameras(node->left,node,cameras,s);
  }
  if(node->right != NULL)
  {
    minimum_cameras(node->right,node,cameras,s);
  }

  if(parent==NULL)//for root node check if included or not or its childern
  {//included or not
    if(!s.count(node))
    {
      cameras++;
    }
    else if(node->left != NULL && !s.count(node->left))
    {
      cameras++;
    }
    else if(node->right!= NULL && !s.count(node->right))
    {
      cameras++;
    }
  }
  else if(node->left != NULL && !s.count(node->left))
  { //for right node of the non-leaf node if not included than set camera
    cameras++;
    s.insert(node);
    s.insert(node->left);
    s.insert(parent);
    if(node->right != NULL)
    {
      s.insert(node->right);
    }
  }
  else if(node->right != NULL && !s.count(node->right))
  { //similiarly for the righ node ot the non-leaft node
    cameras++;
    s.insert(node);
    s.insert(node->right);
    s.insert(parent);
    if(node->left != NULL)//for teaching purpose else it is irrelevant
    {//doesn't effect answer
      s.insert(node->left);
    }
  }

}

int main()
{
  Tree* root = NULL;
  create_node(root, 5);
  create_node(root, 2);
  create_node(root, 6);
  create_node(root, 7);
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
  create_node(root, 16);
  */
  set<Tree*>s;
  int cameras=0;
  Tree* parent = NULL;
  minimum_cameras(root,parent,cameras,s);
  cout << cameras;
}
