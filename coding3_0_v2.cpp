//Implement a stack using linked list. Refer to https://proprogramming.org/c-program-to-implement-stack-using-linked-list/
#include<iostream>
using namespace std;

struct Node{
  int data;
  struct Node *next;
};

class Stack{
  private:
    Node *head;
  public:
    Stack(){head = NULL;}
    bool push(int d);
    int pop();
    int peek();
    bool isempty();
};

bool Stack::push(int d){
  Node *temp= new Node;
  temp->data = d;
  temp->next = head;
  head = temp;
}

int Stack::pop(){
  int tmp;
  if(head != NULL){
    tmp = head->data;
    head = head->next;
  }
  return tmp; 
}

int Stack::peek(){
  return head->data;
}

bool Stack::isempty(){
  if(head == NULL){return true;}
  else{return false;}
}

int main(){
  Stack my_stack;
  my_stack.push(5);
  my_stack.push(21);
  my_stack.push(30);
  my_stack.pop();
  my_stack.pop();
  cout << my_stack.isempty() << endl; 
  cout << my_stack.peek() << endl;
}
