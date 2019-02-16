//palindrome
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

int palindrome(Node *head){
  Node *reverseList = NULL;
  Node *originalList = head;
  while(head != NULL){
    if(reverseList == NULL){
      reverseList = newNode(head->data);
    }
    else{
      Node *temp = newNode(head->data);
      temp->next = reverseList;
      reverseList = temp;
    }
    head = head->next;
  }
  //while(reverseList != NULL){cout << reverseList->data << " "; reverseList = reverseList->next;}
  //cout << endl;
  //while(originalList != NULL){cout << originalList->data << " "; originalList = originalList->next;}
  //cout << endl;
  while(originalList != NULL){
    if(originalList->data == reverseList->data){/*cout << "pass" << endl*/;}
    else{
      //cout << "stop" << endl;
      return 0;
    }
    originalList = originalList->next;
    reverseList = reverseList->next;
  }
  return 1;
}

int main(){
  Node *string = newNode('a'); 
  string->next = newNode('b'); 
  string->next->next = newNode('c'); 
  int x;
  x = palindrome(string);
  if(x){
    cout << " This linked list is a palindrome" << endl;
  }
  else{
    cout << " This linked list is not a palindrome" << endl;

  }
}
