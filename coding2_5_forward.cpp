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

struct Node *sumLists(Node *n1, Node *n2, int *carry){
  if(n1 == NULL){
    return NULL;   
  }
  Node *result = new Node;
  int sum;
  result->next = sumLists(n1->next, n2->next, carry);
  //cout << carry << endl;
  //cout << *carry << endl;
  sum = n1->data + n2->data + *carry;
  *carry = sum/10;
  sum = sum%10;
  result->data = sum;
  return result; 
}

int main(){
  Node *num1 = newNode(6); 
  num1->next = newNode(1); 
  num1->next->next = newNode(7); 
  Node *num2 = newNode(2); 
  num2->next = newNode(9); 
  num2->next->next = newNode(5); 
  int carry = 0;
  Node *sum = sumLists(num1,num2,&carry);
  while(sum != NULL){
    cout << sum->data << " ";
    sum = sum->next;
  }
  cout << endl;
}
