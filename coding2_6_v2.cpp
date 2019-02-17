//palindrome, solution 2, use stack
#include<iostream>
#include<stack>
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
  Node *pt_slow, *pt_fast;
  pt_slow = head;
  pt_fast = head;
  stack<char> char_stack;
  while(pt_fast != NULL and pt_fast->next != NULL){
    char_stack.push(pt_slow->data);
    pt_slow = pt_slow->next;
    pt_fast = pt_fast->next->next;
  }
  while(pt_slow != NULL){
    if(pt_fast != NULL){//odd size
      pt_slow = pt_slow->next;
      if(pt_slow->data == char_stack.top()){
        char_stack.pop();
        if(char_stack.empty()){return 1;}
      }
      else{return 0;}
    }
    else{//even size
      if(pt_slow->data == char_stack.top()){
        char_stack.pop();
        if(char_stack.empty()){return 1;}
      }
      else{return 0;}
      pt_slow = pt_slow->next;
    }
  }
  //if(char_stack.empty()){return 1;}
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
