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
  if(top == MAX-1){return true;}
  else{return false;}
}
int Stack::peek(){
  if(top >= 0){return a[top];}
  else{return 0;}
}

class StackSet{
  public:
    list<Stack> stacks;
    Stack last;
    bool push(int d);
    int pop();
    int peek();
    StackSet(){
      last = stacks.back();
    }
};

int StackSet::pop(){
  return stacks.back().pop();
}

int StackSet::peek(){
  return stacks.back().peek();
}

bool StackSet::push(int d){
  //Stack last;
  if(stacks.empty()){
    Stack first;
    cout << "Stacks is empty, creat a new stack." << endl;
    first.push(d);
    stacks.push_back(first);
    cout << "--Push " << d << " to stack " << stacks.size() << endl;
  }
  else{
    //last = stacks.back();
    //if(last.isfull()){
    if(stacks.back().isfull()){
      Stack new_s;
      new_s.push(d);
      stacks.push_back(new_s);
      cout << "Last is full, creat a new stack." << endl;
      cout << "--Push " << d << " to stack " << stacks.size() << endl;
    }
    else{
      stacks.back().push(d);
      cout << "Push " << d << " to stack " << stacks.size() << endl;
    }
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
