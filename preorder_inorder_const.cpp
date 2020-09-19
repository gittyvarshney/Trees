#include<bits/stdc++.h>
using namespace std;
//Constructing Binary tree from Preorder and inorder traversal
//Based on the fact that preorder contains first element as root the
//left subtree and then right sub Tree
//whereas leftside of inorder contains element which are at left subtree
//and right side contains element which are at right subtree

//so what you have to do is store the indexes of all inorder elements in
// a map when first preorder element enters just used the index to divide and
//conquer the left subtree and right subtree

//Note that this algorithm doesn't work for the tree where we have duplicate
//elements for this refer to implementation using stack and set

//Note for inorder and post order same principle applies but you have to
//take the last element as root
//and thus decrement index to take first right subtree and left subtree

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


void inorder_traverse(Tree*& temp)
{
  if(temp != NULL)
  {
    inorder_traverse(temp->left);
    cout << temp->data << " ";
    inorder_traverse(temp->right);
  }
}


Tree* divide_conquer(vector<int>&pre_order,int& index, int start,int end,map<int,int>&m)
{
  if(start>end)
  {
    return NULL;
  }
  index++;
  int val = pre_order[index]; //first root then left and right subtrees
  Tree* temp = create_node(val);
  int inorder_index = m[val];
  temp->left = divide_conquer(pre_order,index,start,inorder_index-1,m);
  //recurse for the left subtree elements

  temp->right = divide_conquer(pre_order,index,inorder_index+1,end,m);
  //recurse for the right subtree elements

  return temp;
}

Tree* build_tree(vector<int>&in_order, vector<int>&pre_order,int n)
{
  map<int,int>m;
  //storing the indices in map
  for(int i=0;i<n;i++)
  {
    m[in_order[i]] = i;
  }
  int index=-1;
  return divide_conquer(pre_order,index,0,n-1,m);
}

int main()
{
  vector<int>pre_order{ 1, 2, 4,8,9,10,11,5,3,6,7};
  vector<int>in_order{8,4,10,9,11,2,5,1,6,3,7};
  int n = in_order.size();
  Tree* root = build_tree(in_order,pre_order,n);
  inorder_traverse(root);
  cout << "\n";
}
