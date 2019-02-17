//Implement a stack using an array. Refer to https://www.geeksforgeeks.org/stack-data-structure-introduction-program/
//https://www.geeksforgeeks.org/constructors-c/
#include<iostream>
using namespace std;

#define MAX 5 
class stack{
  private:
    int a[MAX];
    int top;
  public:
    stack(){top = -1;}
    bool push(int d);
    int pop();
    bool isempty();
    int peek();
};

bool stack::push(int d){
  if(top >= MAX-1){cout << "Stack overflow." << endl; return false;}
  else{a[++top] = d; return true;}
}
int stack::pop(){
  if(top < 0){cout << "Stack underflow." << endl; return 0;}
  else{return a[top--];}
}
bool stack::isempty(){
  if(top < 0){return true;}
  else{return false;}
}
int stack::peek(){
  if(top >= 0){return a[top];}
  else{return 0;}
}


int main(){
  stack my_stack;
  my_stack.push(5);
  my_stack.push(21);
  my_stack.push(3);
  my_stack.push(4);
  my_stack.push(9);
  my_stack.push(30);
  my_stack.pop();
  cout << my_stack.peek() << endl;
  cout << my_stack.isempty() << endl; 
}
