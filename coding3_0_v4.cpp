//Implement queue, use linked list
#include<iostream>
using namespace std;

struct Node{
  int data;
  struct Node *next;
};

class Stack{
  private:
    Node *head;
    Node *tail;
  public:
    Stack(){
      head = NULL;
      tail = NULL;
    }
    bool push(int d);
    int pop();
    bool isempty();
    int peek();
};

bool Stack::push(int d){
  if(head == NULL){
    Node *temp = new Node;
    temp->data = d;
    temp->next = NULL;
    head = temp;
    tail = head;
  }
  else{
    Node *temp = new Node;
    temp->data = d;
    temp->next = NULL;
    tail->next = temp;
    tail = tail->next;
  }
}

int Stack::pop(){
  int x = head->data;
  head = head->next;
  return x;
}

bool Stack::isempty(){
  if(head == NULL){return true;}
  else{return false;}
}

int Stack::peek(){
  return head->data;
}

int main(){
  Stack s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  cout << s.peek() << endl;
  s.pop();
  cout << s.peek() << endl;
  cout << s.isempty() << endl;
  s.pop();
  cout << s.peek() << endl;
  s.pop();
  cout << s.peek() << endl;
  s.pop();
  cout << s.isempty() << endl;
}

