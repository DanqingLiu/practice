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

int validateBST(Node *root){
  if(root->left == NULL and root->right == NULL){
    return true;
  }
  else if(root->left == NULL and root->right != NULL){
    if(root->data < root->right->data){
      validateBST(root->right);
    }
    else{return false;}
  }
  else if(root->right == NULL and root->left != NULL){
    if(root->data > root->left->data){
      validateBST(root->left);
    }
    else{return false;}
  }
  else if (root->data > root->left->data and root->data < root->right->data){
    validateBST(root->left);
    validateBST(root->right);
  }
  else{
    return false;
  }
}
  
int main() 
{ 
  struct Node *root = newnode(8); 
  root->left        = newnode(6); 
  root->right       = newnode(2); 
  root->left->left  = newnode(5); 
  root->left->right = newnode(7); 
  root->left->left->left  = newnode(3); 
 
  bool isBST = validateBST(root);
  cout << "is a binary search tree? " << isBST << endl;
  return 0; 
} 
