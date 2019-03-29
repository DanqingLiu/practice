/* 
Validate BST
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

bool validateBST(Node *root, int min, int max){
  if(root == NULL){
    return true;
  }
  else if((min != NULL and root->data < min) or (max != NULL and root->data > max)){
    return false;
  }
  else if(!validateBST(root->left, min, root->data) or !validateBST(root->right, root->data, max)){
    return false;
  }
  else{
    return true;
  }
}
  
int main(){ 
  struct Node *root = newnode(8); 
  root->left        = newnode(6); 
  root->right       = newnode(12); 
  root->left->left  = newnode(5); 
  root->left->right = newnode(9); 
  root->left->left->left  = newnode(3); 
 
  int min = NULL;
  int max = NULL;
  bool isBST = validateBST(root, min, max);
  cout << "is a binary search tree? " << isBST << endl;
  return 0; 
} 
