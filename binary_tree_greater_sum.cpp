#include<bits/stdc++.h>
using namespace std;
//in this question you have previlage to either not choose any
//path so that the sum should never be negative
//it is different from leetcode quetion in that way
//in case you have to choose atleast one node then prior answer is INT_MAX
//and 0 should not be returned
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

//return max out of a,b,c,d,e
int max_function(int a,int b,int c,int d,int e)
{
  a = max(a,b);
  c = max(c,d);
  a = max(a,c);
  return max(a,e);
}

//int this question it is  to be noted that the maximum sum can be formed
//as left->val + node->val + right->val so it is also to be considered

int recurr_for_path(Tree*& root, int&ans)//answer should be in reference so that
{//it remained original thoughtout iteration and not any copy of it generated

  if(root == NULL)
  {
    return 0;
  }

  //first get the data from left and right nodes to do some analysis
  int l = recurr_for_path(root->left,ans);
  int r = recurr_for_path(root->right,ans);

  //answer shall be from the following:-
  //if previous ans is greater or current node or current node + left
  // or  current node + right or current node + left + right
  ans = max_function(ans,root->data,root->data+l,root->data+r,root->data+l+r);

  //Now what should be given to the parent so it should be the best
  //path which is either itself or itself+left or itself+right
  //if all are negative than we not considering its child so return 0

  return max_function(root->data,root->data+l,root->data+r,0,0);//extra 0 is added to use
  //our predefined function
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
  cout << "The Maximum sum path possible is : ";
  int ans= 0;
  recurr_for_path(root,ans);
  cout << ans << "\n";
}
