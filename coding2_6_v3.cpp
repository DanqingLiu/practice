//palindrome, solution 3, recursive. Refer to https://www.geeksforgeeks.org/recursive-function-check-string-palindrome/
#include<iostream>
using namespace std;

struct Node{
  char data;
  struct Node *next;
};

struct Node *newNode(char x){
  Node *temp = new Node;
  temp->data = x;
  temp->next = NULL;
  return temp;
}

int Length(Node *head){
  int i = 0;
  while(head != NULL){
    head = head->next;
    i++;
  }
  return i;
}

bool palindrome(Node *head, int length){
  if(length == 0 or length == 1 ){
    return true;
  }
  Node *tail = head;
  for(int i=0;i<length-1;i++){
    tail = tail->next;
  }
  if(head->data == tail->data){
    palindrome(head->next, length-2);
  }
  else{return false;}
}

int main(){
  Node *string = newNode('a'); 
  string->next = newNode('b'); 
  string->next->next = newNode('c'); 
  bool x;
  int n = Length(string);
  x = palindrome(string, n);
  if(x){
    cout << " This linked list is a palindrome" << endl;
  }
  else{
    cout << " This linked list is not a palindrome" << endl;

  }
}
