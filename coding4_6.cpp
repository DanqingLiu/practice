/* 
Successor
https://www.geeksforgeeks.org/binary-search-tree-insert-parent-pointer/
*/
#include<iostream>
#include<limits>
#include <cstdlib>
using namespace std;

struct Node{
  int data;
  struct Node *left;
  struct Node *right;
  struct Node *parent;
};

struct Node* newnode(int data){ 
  Node *node = new Node;
  node->data = data; 
  node->left = NULL; 
  node->right = NULL; 
  node->parent = NULL; 
  return node; 
} 

Node *getMin(Node *n){
  while(n->left != NULL){
    n = n->left;
  }
  return n;
}

Node *findNext(Node *n){
  if(n == NULL) return NULL;
  else{
    if(n->right != NULL){
      getMin(n->right);
    }
    else{
      Node *q = n;
      Node *x = n->parent;
      while(q != x->left){
        q = x;
        x = x->parent;
      }
      return x;
    }
  }
}
  
struct Node* insert(struct Node* node, int key){ 
  if(node == NULL) return newnode(key); 
  if(key < node->data){ 
    Node *lchild = insert(node->left, key); 
    node->left  = lchild; 
    lchild->parent = node; 
  } 
  else if(key > node->data){ 
    Node *rchild = insert(node->right, key); 
    node->right  = rchild; 
    rchild->parent = node; 
  } 
  return node; 
} 
  
int main(){ 
  struct Node *root = NULL; 
  root = insert(root, 20); 
  insert(root, 15); 
  insert(root, 30); 
  insert(root, 14); 
  insert(root, 18); 
  insert(root, 16); 
  insert(root, 25); 
  Node *n = findNext(root);
  cout << "The next of " << root->data << " is " << n->data << endl;
  Node *m = findNext(root->left->right);
  cout << "The next of " << root->left->right->data << " is " << m->data << endl;
  return 0; 
} 
