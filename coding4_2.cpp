//Minimal tree.
#include<iostream>
using namespace std;

struct Node{
  int data;
  struct Node *left;
  struct Node *right;
};

Node *bst(int a[], int n){
  //int n = sizeof(a)/sizeof(a[0]);//https://www.geeksforgeeks.org/using-sizof-operator-with-array-paratmeters/
  //cout << n << endl;
  if(n==1){
    Node *leaf = new Node;
    leaf->data = a[0];
    leaf->left = NULL;
    leaf->right = NULL;
    return leaf;
  }
  else{
    int i = n/2;
    int left_a[i];
    if(n>2){
        int right_a[n-i-1];
        Node *root = new Node;
        root->data = a[i];
        cout << "root: " << root->data << endl;
        for(int k=0;k<i;k++){
          left_a[k] = a[k];
        }
        for(int k=i+1;k<n;k++){
          right_a[k-i-1] = a[k];
        } 
        root->left = bst(left_a, i);
        root->right = bst(right_a, n-i-1);
      }
    else if(n == 2){
        Node *root = new Node;
        root->data = a[i];
        cout << "root: " << root->data << endl;
        left_a[0] = a[0];
        root->left = bst(left_a, 1);
        root->right = NULL;
      }
  }
}

int main(){
  int n = 8;
  int a[n] = {31,2,3,4,5,6,7,8};
  bst(a, n);
}
