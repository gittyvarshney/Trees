#include<bits/stdc++.h>
using namespace std;
//The square root decomposition is simply an approach to
//reduce the time complexity if you have various queries which
//can take O(n) on each.
//from this approach we can reduce the time complexity of each query to
//sqrt(n)

//note that dfs in graphs is less time consuming than dfs
//in n-arry tree from the fact that the previous node from it
//can come should always be it's parent
//so you don't have to store each node traversed in a set
//also note that n-arry tree is a directed graph type


int height=-1;
int blocks_size; //size of each block i.e. sqrt(height_of_tree);
map<int,int>parent; //have to store parent of each node
map<int,int>block_parent; //block parent of each node for sqrt decompose

map<int,int>depth; //depth of each node

bool add_edge(map<int,vector<int>> &m, int a, int b)
{
	for(auto i: m[a])
	{
		if(i == b)
		{
			return false;
		}
	}
	m[a].emplace_back(b);
  parent[b] = a;
	return true;
}

void block_creation(map<int,vector<int>> &m,int root,int h)
{
  int prev = root;
	for(auto i: m[root])
  {
    if(h%blocks_size != 0)
    {
      block_parent[i] = block_parent[prev];
    }
    else
    {
      block_parent[i] = prev;
    }
    depth[i] = h;
    block_creation(m,i,h+1);
  }
}

void height_dfs(map<int,vector<int>> &m,int root,int h,int& max_height)
{
  if(h>max_height)
  {
    max_height = h;
  }

	for(auto i : m[root])
	{
		height_dfs(m,i,h+1,max_height);
	}
}

int in_block_jump(int a, int b)
{
  if(a == b)
  {
    return a;
  }

  if(depth[a]>depth[b])
  {
    swap(a,b);
  }

  while(depth[a]!=depth[b]) // make same depth of both the nodes
  {
    b = parent[b];
  }

  while(a != b) // when at same depth just iterate to the parent
  {
    a = parent[a];
    b = parent[b];
  }

  return a;
}

int block_jump(int a, int b)
{
  if(a == b)
  {
    return a;
  }

  while(block_parent[a]!=block_parent[b]) // block jumps so that both have
  {//same block parents i.e. same block number
    if(depth[a]>depth[b]) // if a goes to higher depth just swap them or otherwise use if else
    {
      swap(a,b);
    }
    b = block_parent[b];
  }

  return in_block_jump(a, b);

}

int main()
{
 /*
  #ifndef ONLINE_JUDGE
    freopen("D:\\Project Sunrise\\input.txt", "r", stdin);
    freopen("D:\\Project Sunrise\\output.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  */
  //implementation of undirected graph
  map<int,vector<int>> m; //vector creation using map & vector int
  int root = 1;
  add_edge(m,1,2);
  add_edge(m,1,3);
  add_edge(m,1,4);
  add_edge(m,2,5);
  add_edge(m,2,6);
  add_edge(m,3,7);
  add_edge(m,4,8);
  add_edge(m,4,9);
  add_edge(m,9,10);
  add_edge(m,9,11);
  add_edge(m,7,12);
  add_edge(m,7,13);
  //first we have to calculate the height of the n-arry tree
  height_dfs(m,1,1,height);

  blocks_size = sqrt(height); //size of each block in sqrt decomposition

  block_parent[root] = -1;
  parent[root] = -1; //the root has no parent whatsoever
  depth[root] = 0; // zero as a reference height of root

  block_creation(m,root,1); //create blocks i.e. create their block parents

  //executing queries
  cout << block_jump(6,9) << "\n";
  cout << block_jump(3,13) << "\n";

}
