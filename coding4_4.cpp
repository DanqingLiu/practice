/* Check balanced
*/
#include<iostream>
#include<list>
#include<vector>
using namespace std;

struct Node{
  int data;
  struct Node *left;
  struct Node *right;
  int height;
};

struct Node* newnode(int data){ 
  Node *node = new Node;
  node->data = data; 
  node->left = NULL; 
  node->right = NULL; 
  node->height = 0;
  return node; 
} 

void updateHeight(Node &root){
  if(root == NULL){return;}
  else if(root->left == NULL and root->right == NULL){
  cout << "-------" << root->data << " : " << root->height << endl;
    root->height = 1;
  }
  else if(root->left == NULL and root->right->height > 0){
    cout << "--" << endl;
    root->height = root->right->height + 1;
  }
  else if(root->right == NULL and root->left->height > 0){
    cout << "---" << endl;
    root->height = root->left->height + 1;
  }
  else if(root->left->height > 0 and root->right->height > 0){
    cout << "----" << endl;
    if (root->left->height > root->right->height ){
      root->height = root->left->height + 1;}
    else{root->height = root->right->height + 1;}
  }
  updateHeight(root->left);
  updateHeight(root->right);
}

bool checkBalance(Node *root){
  if(root == NULL){return true;}
  else if(root->left == NULL and root->right == NULL){return true;}
  else if(root->left == NULL and root->right->height > 1){return false;}
  else if(root->right == NULL and root->left->height > 1){return false;}
  if(root->left->height - root->right->height > 1 or root->left->height - root->right->height < -1){
    return false;
  }
  checkBalance(root->left);
  checkBalance(root->right);
}
  
int main() 
{ 
  struct Node *root = newnode(6); 
  root->left        = newnode(9); 
  root->right       = newnode(3); 
  root->left->left  = newnode(4); 
  root->left->right = newnode(5); 
  root->left->left->left  = newnode(7); 
 
  updateHeight(root);
  bool isbalance = checkBalance(root);
  cout << "isbalance? " << isbalance << endl;
  return 0; 
} 
