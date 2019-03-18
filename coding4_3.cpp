//List of depths
//https://www.quora.com/How-do-you-create-an-array-of-linkedlist-in-C++
#include<iostream>
#include<list>
#include<vector>
using namespace std;

struct Node{
  int data;
  struct Node *left;
  struct Node *right;
};

list<int> *listsDepth(Node *root, int depth){
  cout << "depth: " << depth << endl;
  if(root->left == NULL or root->right == NULL){
    return NULL;
  }
  list<int> *list_depth[5];
  (*list_depth[depth]).push_back(root->data);
  cout << " -- " << endl;
  depth++;
  listsDepth(root->left, depth);
  listsDepth(root->right, depth);
  return *list_depth; 
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
  struct Node *root = newnode(1); 
  root->left        = newnode(2); 
  root->right       = newnode(3); 
  root->left->left  = newnode(4); 
  root->left->right = newnode(5); 
  root->left->left->left  = newnode(7); 
  
  list<int> *x; 
  x = listsDepth(root, 0); 
  for(int i = 0; i<5; i++){
    for(list<int>::iterator j = x[i].begin(); j != x[i].end(); ++j)
      {cout << *j << endl;}
  }
  return 0; 
} 
