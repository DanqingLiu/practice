//Implement a stack using an array. Refer to https://www.geeksforgeeks.org/stack-data-structure-introduction-program/
//https://www.geeksforgeeks.org/constructors-c/
#include<iostream>
#include<list>
using namespace std;

#define MAX 3 
class Stack{
  private:
    int a[MAX];
    int top;
  public:
    Stack(){top = -1;}
    bool push(int d);
    int pop();
    bool isempty();
    bool isfull();
    int peek();
};

bool Stack::push(int d){
  if(top >= MAX-1){cout << "Stack overflow." << endl; return false;}
  else{a[++top] = d; return true;}
  cout << top << endl;
}
int Stack::pop(){
  if(top < 0){cout << "Stack underflow." << endl; return 0;}
  else{return a[top--];}
}
bool Stack::isempty(){
  if(top < 0){return true;}
  else{return false;}
}
bool Stack::isfull(){
  if(top == MAX-2){return true;}
  else{return false;}
}
int Stack::peek(){
  if(top >= 0){return a[top];}
  else{return 0;}
}

class StackSet{
  public:
    list<Stack> stacks;
    bool push(int d);
    int pop();
};

bool StackSet::push(int d){
  Stack last;
  if(stacks.empty()){
    cout << "Stacks is empty, creat a new stack." << endl;
    last.push(d);
    stacks.push_back(last);
    cout << "--Push " << d << " to stack " << stacks.size() << endl;
  }
  else if(last.isfull()){
    Stack s;
    s.push(d);
    stacks.push_back(s);
    cout << "Last is full, creat a new stack." << endl;
    cout << "--Push " << d << " to stack " << stacks.size() << endl;
  }
  else{
    last.push(d);
    cout << "Push " << d << " to stack " << stacks.size() << endl;
  }
}

int main(){
  StackSet s;
  s.push(5);
  s.push(21);
  s.push(3);
  s.push(4);
  s.push(9);
  s.push(30);
  s.push(0);
  s.push(7);
  //s.pop();
}
