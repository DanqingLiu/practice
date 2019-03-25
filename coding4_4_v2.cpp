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
};

struct Node* newnode(int data){ 
  Node *node = new Node;
  node->data = data; 
  node->left = NULL; 
  node->right = NULL; 
  return node; 
} 

int getHeight(Node *root){
  if(root == NULL){return 0;}
  int left_height = getHeight(root->left);
  int right_height = getHeight(root->right);
  if (left_height > right_height){
    return left_height + 1;
  }
  else{
    return right_height + 1;
  }
}

bool checkBalance(Node *root){
  if (root == NULL){return true;}
  else if (root->left == NULL){
    if (root->right == NULL or getHeight(root->right) == 1){return true;}
    else {return false;}
  }
  else if (root->right == NULL){
    if (root->left == NULL or getHeight(root->left) == 1){return true;}
    else {return false;}
  }
  else{
    int left_height = getHeight(root->left);
    int right_height = getHeight(root->right);
    if (left_height - right_height > 1 or left_height - right_height < -1){
      return false;
    }
    else{
      checkBalance(root->left);
      checkBalance(root->right);
    }
  }
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
