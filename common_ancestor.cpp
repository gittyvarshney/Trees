#include<bits/stdc++.h>
using namespace std;
//Lowest common ancestor
//in this question you have to find the desired node out of two
//if founded you have to return true to the parent otherwise false
//but before returning true to the parent you have to check if the other
//node is not located as its child if located you just have to print that node
//if a node have both true outcomes then it is a common ancestor


bool flag;

class Tree
{
public:
  int data;
  Tree* left;
  Tree* right;
};

Tree* create_node(int n)
{
  Tree* new_node = new Tree();
  new_node->data = n;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}


void in_order(Tree*& temp)
{
  if(temp != NULL)
  {
    in_order(temp->left);
    cout << temp->data << " ";
    in_order(temp->right);
  }
}

bool common_ancestor(Tree*& temp,int&a,int&b)
{
  if(temp == NULL)
  {
    return false;
  }

  if(temp->data == a || temp->data == b) //search parent for next desired node
  {
    if(common_ancestor(temp->left,a,b) || common_ancestor(temp->right,a,b))
    { //if it is found just print it
      cout << temp->data << " ";
      flag = true;
    }
    return true;
  }

  //otherwise just check the left and right nodes
  bool x = common_ancestor(temp->left,a,b);
  bool y = common_ancestor(temp->right,a,b);

  if((x == true && y== false) || (x == false && y == true))
  {
    return true;
  }
  else if(x== true && y== true)
  {
    cout << temp->data << " ";
    flag = true;
    return true;
  }
  else
  {
    return false;
  }
}

int main()
{
  Tree* root = NULL;
  //Simple binary tree creation
  root = create_node(1);
  //Sub tree left
  root->left = create_node(2);
  root->left->left = create_node(4);
  root->left->right = create_node(5);
  //Sub tree right
  root->right = create_node(3);
  root->right->left = create_node(6);
  root->right->right = create_node(7);

  in_order(root);
  cout << "\n";
  int a = 3;
  int b = 1;
  flag = false;
  common_ancestor(root,a,b);
  if(flag==false)
  {
    cout << "no ancestor found \n";
  }
  flag = false;

}
