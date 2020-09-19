#include<bits/stdc++.h>
using namespace std;
//construction of binary search tree from postorder traversal
//based on the fact that the last element is the node and
//every greater element from iterating in reverse is root->right
//when you encounter the lesser element just pop the elements from the stack
//until you find the shorter element and make it as temp->left of that last
//bigger element

//Same logic can be applied to the preorder traversal

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

void pre_order(Tree*& temp)
{
  if(temp != NULL)
  {
    cout << temp->data << " ";
    pre_order(temp->left);
    pre_order(temp->right);
  }
}

void post_order_traverse(Tree*& temp)
{
  if(temp != NULL)
  {
    post_order_traverse(temp->left);
    post_order_traverse(temp->right);
    cout << temp->data << " ";
  }
}

void build_bst(Tree* root,int k,vector<int>&post_order)
{
  stack<Tree*>st;
  st.push(root);
  Tree* temp;
  for(int i=k;i>=0;i--)
  {
    temp = st.top();
    if(post_order[i] >= temp->data) //for greater element just make them right child
    {
      temp->right = create_node(post_order[i]);
      st.push(temp->right);
    }
    else
    {//for shorter element you have to traverse the stack to get the last bigger
      //element
      while(!st.empty() && st.top()->data > post_order[i])
      {
        temp = st.top();
        st.pop();
      }
      temp->left = create_node(post_order[i]);
      st.push(temp->left);
    }
  }
}

int main()
{
  vector<int>post_order{2,4,3,7,9,8,5,12,14,13,16,18,17,15,10};
  int n = post_order.size();
  Tree* root = create_node(post_order[n-1]);
  build_bst(root,n-2,post_order);
  cout << "\nprinting in  post Order: ";
  post_order_traverse(root);
}
