//Sum lists, ref to https://www.geeksforgeeks.org/sum-of-two-linked-lists/
#include<iostream>
using namespace std;

struct Node{
  int data;
  struct Node *next;
};

struct Node *newNode(int d){
  Node *temp = new Node;
  temp->data = d;
  temp->next = NULL;
  return temp;
}

struct Node *sameSizesum(Node *n1, Node *n2, int *carry){
  if(n1 == NULL){
    return NULL;   
  }
  Node *result = new Node;
  int sum;
  result->next = sameSizesum(n1->next, n2->next, carry);
  //cout << carry << endl;
  //cout << *carry << endl;
  sum = n1->data + n2->data + *carry;
  *carry = sum/10;
  sum = sum%10;
  result->data = sum;
  return result; 
}

int Length(Node* head){
  int i = 0;
  while(head != NULL){
    head = head->next;
    i++;
  }
  return i;
}

struct Node *diffSizesum(Node *n1, Node *n2, int *carry){
  int l1 = Length(n1);
  int l2 = Length(n2);
  int diff = l2 - l1;
  Node *newn1 = n1;
  for(int i=0; i<diff; i++){
    Node *temp = newn1;
    newn1 = newNode(0);
    newn1->next = temp;
  }
  Node *result = sameSizesum(newn1, n2, carry);
  return result;
}

struct Node *listsSum(Node *n1, Node *n2, int *carry){
  int l1 = Length(n1);
  int l2 = Length(n2);
  Node *result = NULL;
  if(l1 == l2){
    result = sameSizesum(n1,n2,carry);
  } 
  else if(l1 > l2){
    result = diffSizesum(n2,n1,carry);
  } 
  else{
    result = diffSizesum(n1,n2,carry);
  } 
  return result;
}

int main(){
  Node *num1 = newNode(6); 
  num1->next = newNode(1); 
  num1->next->next = newNode(7); 
  Node *num2 = newNode(2); 
  num2->next = newNode(9); 
  num2->next->next = newNode(5); 
  num2->next->next->next = newNode(1); 
  int carry = 0;
  Node *sum = listsSum(num1,num2,&carry);
  while(sum != NULL){
    cout << sum->data << " ";
    sum = sum->next;
  }
  cout << endl;
}
