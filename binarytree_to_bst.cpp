#include<bits/stdc++.h>
using namespace std;
//The idea is simple first traverse the tree in inorder traversal
//and store the keys in vector array
//then sort the vector array
//then insert the values of vector array to nodes again traversing the
//tree in inorder traversal
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

void extract_keys(Tree*& temp,vector<int>& v)
{
  if(temp != NULL)
  {
    extract_keys(temp->left,v);
    v.emplace_back(temp->data);
    extract_keys(temp->right,v);
  }
}

void insert_keys(Tree*& temp,vector<int>::iterator& it)
{
  if(temp != NULL)
  {
    insert_keys(temp->left,it);
    temp->data = *it;
    it++;
    insert_keys(temp->right,it);
  }
}

int main()
{
  Tree* root = NULL;
  //Simple binary tree creation
  root = create_node(20);
  //Sub tree left
  root->left = create_node(15);
  root->left->left = create_node(7);
  root->left->right = create_node(20);
  root->left->left->left = create_node(15);
  root->left->left->right = create_node(9);
  root->left->right->left = create_node(11);
  root->left->right->right = create_node(8);
  //Sub tree right
  root->right = create_node(16);
  root->right->left = create_node(1);
  root->right->right = create_node(3);
  root->right->left->left = create_node(10);
  root->right->left->right = create_node(4);
  root->right->right->left = create_node(12);
  root->right->right->right = create_node(13);
  in_order(root);
  cout << "\n";
  vector<int>v;
  extract_keys(root,v);
  sort(v.begin(),v.end());
  vector<int>::iterator it;
  it = v.begin();
  insert_keys(root,it);
  in_order(root);
}
