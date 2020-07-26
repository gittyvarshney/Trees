#include<bits/stdc++.h>
using namespace std;
//This is a very cool question all you have to do is a way to store the parents
//of visited nodes so that you can find the nodes at distance upward the sub Tree
//after that all you have to do is breath first search
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

void level_order(Tree*& root,map<Tree*,Tree*>&parent,int k)
{
  Tree* temp = root;
  if(temp == NULL)
  {
    return;
  }
  queue<pair<Tree*,int>> q;
  set<Tree*> s;
  q.push(make_pair(temp,0));
  while(!q.empty())
  {
    s.insert(q.front().first); //inserting the visited nodes in set
    if(q.front().second == k)
    { //if distance equals you just prints it
      cout << q.front().first->data << " ";
    }
    else if(q.front().second < k)
    {
      //push left if distance is still less
      if(q.front().first->left != NULL && s.count(q.front().first->left)<1)
      {
        q.push(make_pair(q.front().first->left,q.front().second+1));
      }
      //similiary push right
      if(q.front().first->right != NULL && s.count(q.front().first->right)<1)
      {
        q.push(make_pair(q.front().first->right,q.front().second+1));
      }
      //if parent exists push parent also
      if(parent.find(q.front().first)!= parent.end())
      {
        q.push(make_pair(parent[q.front().first],q.front().second+1));
      }
    }
    else
    {
      break;
    }
    q.pop();
  }
}

void all_node_k(Tree*& root,int target,int k,map<Tree*,Tree*>&parent)
{ //this is a function to store parents of all nodes visited till the target
  //is not found in hashed map if it is found then all we have to do is
  //level order traversal
  if(root == NULL)
  {
    return;
  }
  if(target< root->data)
  {
    parent[root->left] = root;
    all_node_k(root->left,target,k,parent);
  }
  else if(target> root->data)
  {
    parent[root->right] = root;
    all_node_k(root->right,target,k,parent);
  }
  else
  {
    level_order(root,parent,k);
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
  cout << "Printing in node at k: ";
  map<Tree*,Tree*>parent;
  all_node_k(root,12,3,parent);
}
