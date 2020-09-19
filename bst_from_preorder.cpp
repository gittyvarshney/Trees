#include<bits/stdc++.h>
using namespace std;
//construction of binary search tree from preorder traversal
//based on the fact that the first element is the node and
//every shorter element from iteration is root->right push it to stack
//when you encounter the bigger element just pop the elements from the stack
//until you find the bigger element and make it as temp->left of that last
//shorter element

//Same logic can be applied to the postorder traversal

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

void pre_order_traverse(Tree*& temp)
{
  if(temp != NULL)
  {
    cout << temp->data << " ";
    pre_order_traverse(temp->left);
    pre_order_traverse(temp->right);
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
  for(int i=1;i<k;i++)
  {
    temp = st.top();
    if(post_order[i] < temp->data) //for lesser element just make them left child
    {
      temp->left = create_node(post_order[i]);
      st.push(temp->left);
    }
    else
    {//for greater element you have to traverse the stack to get the last shorter
      //element
      while(!st.empty() && st.top()->data <= post_order[i])
      {
        temp = st.top();
        st.pop();
      }
      temp->right = create_node(post_order[i]);
      st.push(temp->right);
    }
  }
}

int main()
{
  vector<int>post_order{10,5,3,2,4,8,7,9,15,13,12,14,17,16,18};
  int n = post_order.size();
  Tree* root = create_node(post_order[0]);
  build_bst(root,n,post_order);
  cout << "\nprinting in  post Order: ";
  pre_order_traverse(root);
}
