//Sum lists
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

struct Node *sumLists(Node *n1, Node *n2){
  Node *n_sum, *pt1;
  int digit_sum;
  int digit1;
  int digit2;
  digit_sum = n1->data + n2->data;
  digit1 = digit_sum%10;
  digit2 = digit_sum/10;
  pt1 = newNode(digit1);
  n1 = n1->next;
  n2 = n2->next;
  n_sum = pt1;
  while(n1 != NULL or n2 != NULL){
    if(n1 == NULL){
      pt1->next = newNode(digit2 + n2->data);
      n2 = n2->next;
      digit2 = 0;
      pt1 = pt1->next;
    }
    else if(n2 == NULL){
      pt1->next = newNode(digit2 + n1->data);
      n1 = n1->next;
      digit2 = 0;
      pt1 = pt1->next;
    }
    else{
      digit_sum = n1->data + n2->data + digit2;
      digit1 = digit_sum%10;
      digit2 = digit_sum/10;
      pt1->next = newNode(digit1);
      n1 = n1->next;
      n2 = n2->next;
      pt1 = pt1->next;
    }
  }  
  return n_sum;
}

int main(){
  Node *num1 = newNode(7); 
  num1->next = newNode(1); 
  num1->next->next = newNode(6); 
  Node *num2 = newNode(5); 
  num2->next = newNode(9); 
  num2->next->next = newNode(2); 
  Node *sum = NULL;
  sum = sumLists(num1,num2);
  while(sum != NULL){
    cout << sum->data << " ";
    sum = sum->next;
  }
  cout << endl;
}
