#include<bits/stdc++.h>
using namespace std;
//for printing level wise leftmost and rightmost nodes of binary Tree
//take the size of initial tree and run for loop for that size on
//that for loop pop the previous elements and push the new children(new level)
//this is the way to ensure the levels of the  binary Tree
//now only have to print first and last element of that for loop

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

void leftmost_rightmost(Tree*& root)
{
  Tree* temp = root;
  if(temp == NULL)
  {
    return;
  }
  int val;
  queue<Tree*>q;
  q.push(temp);
  while(!q.empty())
  {
    int n = q.size();//size of new level
    for(int i=0;i<n;i++) //for loop for the number of elements in queue
    {
      val = q.front()->data;
      if(i==0 || i==n-1) //for frst and last
      {
        cout << val << " ";
      }
      if(q.front()->left != NULL)
      {
        q.push(q.front()->left); //push new level elemnts
      }
      if(q.front()->right != NULL)
      {
        q.push(q.front()->right);//push new level elements
      }
      q.pop(); //pop the old levels elements
    }
    cout << "\n";
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
  cout << "Printing in Leftmost and Rightmost Element : \n";
  leftmost_rightmost(root);
}
