/* List of depths
https://www.quora.com/How-do-you-create-an-array-of-linkedlist-in-C++
https://www.geeksforgeeks.org/c-program-hashing-chaining/
*/
#include<iostream>
#include<list>
#include<vector>
using namespace std;

struct Node{
  int data;
  struct Node *left;
  struct Node *right;
};

//depth == hash index
list<int> *hashTable(Node *root, int depth, list<int> *table){
  if(root == NULL){
    return NULL;
  }
  cout << "node: " << root->data << "--> depth: " << depth << endl;
  table[depth].push_back(root->data);
  cout << " -- " << endl;
  depth++;
  hashTable(root->left, depth, table);
  hashTable(root->right, depth, table);
  return table; 
}

struct Node* newnode(int data){ 
  Node *node = new Node;
  node->data = data; 
  node->left = NULL; 
  node->right = NULL; 
  
  return node; 
} 
  
int main() 
{ 
  struct Node *root = newnode(6); 
  root->left        = newnode(9); 
  root->right       = newnode(3); 
  root->left->left  = newnode(4); 
  root->left->right = newnode(5); 
  root->left->left->left  = newnode(7); 
  
  list<int> *x; 
  list<int> *table; //std::list<int> myListArray[10];	// C-style array of lists
  table = new list<int>[4];//Suppose the depth of the tree is given
  x = hashTable(root, 0, table); 
  for(int i = 0; i<4; i++){
    {cout << "Link list: " << i+1 << endl;}
    for(list<int>::iterator j = x[i].begin(); j != x[i].end(); ++j)
      {cout << *j << endl;}
  }
  return 0; 
} 
