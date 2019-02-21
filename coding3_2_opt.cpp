//Stack min.
#include<iostream>
using namespace std;

struct Node{
  int data;
  struct Node *next;
};

class Stack{
  private:
    Node *head;
    Node *min_head;
  public:
    Stack(){
      head = NULL;
      min_head = NULL;
    }
    bool push(int d);
    int pop();
    int peek();
    bool isempty();
    int min();
};

bool Stack::push(int d){
  Node *temp= new Node;
  temp->data = d;
  temp->next = head;
  head = temp;
  if(min_head == NULL){
    min_head = temp;
  }
  else if(d < min_head->data){
    temp->next = min_head;
    min_head = temp;
  }
  else{
    Node *temp2 = new Node;
    temp2->data = min_head->data;
    temp2->next = min_head;
    min_head = temp2;
  }
}

int Stack::pop(){
  int tmp;
  if(head != NULL){
    tmp = head->data;
    //if(tmp == min_head->data){min_head = min_head->next;}
    min_head = min_head->next;
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

int Stack::min(){
  return min_head->data;
}

int main(){
  Stack my_stack;
  my_stack.push(5);
  my_stack.push(21);
  my_stack.push(30);
  cout << "is empty? " << my_stack.isempty() << endl; 
  cout << "peek: " << my_stack.peek() << endl;
  cout << "min: " << my_stack.min() << endl;
}
