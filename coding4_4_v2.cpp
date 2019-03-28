/* Check balanced
*/
#include<iostream>
#include<list>
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

int getHeight(Node *root){
  if(root == NULL){return -1;}
  int left_height = getHeight(root->left);
  int right_height = getHeight(root->right);
  if (abs(left_height - right_height) > 1){
    return numeric_limits<int>::min();
  }
  else{
    return max(left_height, right_height) + 1;
  }
}

bool checkBalance(Node *root){
  return getHeight(root) != numeric_limits<int>::min();
}
  
int main() 
{ 
  struct Node *root = newnode(6); 
  root->left        = newnode(9); 
  root->right       = newnode(3); 
  root->left->left  = newnode(4); 
  root->left->right = newnode(5); 
  root->left->left->left  = newnode(7); 
 
  bool isbalance = checkBalance(root);
  cout << "isbalance? " << isbalance << endl;
  return 0; 
} 
