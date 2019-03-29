/* 
Successor
*/
#include<iostream>
#include<limits>
#include <cstdlib>
using namespace std;

struct Node{
  int data;
  struct Node *left;
  struct Node *right;
};

struct Node* newnode(int data){ 
  Node *node = new Node;
  node->data = data; 
  node->left = NULL; 
  node->right = NULL; 
  return node; 
} 

Node *getMin(Node *root){
  if(root->left == NULL){
    return root;
  }
  else{
    getMin(root->left);
  }
}
  
int main(){ 
  struct Node *root = newnode(8); 
  root->left        = newnode(6); 
  root->right       = newnode(12); 
  root->left->left  = newnode(5); 
  root->left->right = newnode(7); 
  root->left->left->left  = newnode(3); 
 
  Node *next = getMin(root->right);
  cout << "The next node of root: " << next->data << endl;
  return 0; 
} 
