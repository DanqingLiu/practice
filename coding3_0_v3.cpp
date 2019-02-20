//Implement queue, use array
#include<iostream>
using namespace std;

#define MAX 3
class Stack{
  private:
    int top;
    int tail;
    int a[MAX];
  public:
    Stack(){
      top = 0;
      tail = -1;
    }
    bool push(int d);
    int pop();
    bool isempty();
    int peek();
};

bool Stack::push(int d){
  if(tail >= MAX - 1){cout << "Stack overflow." << endl; return false;}
  else{a[++tail] = d; return true;}
}
 
int Stack::pop(){
  if(top > tail){cout << "Stack underflow." << endl; return 0;}
  else{return a[top++];}
}

bool Stack::isempty(){
  if(top > tail){return true;}
  else{return false;}
}

int Stack::peek(){
  return a[top];
}
 
int main(){
  Stack s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.pop();
  cout << s.peek() << endl; 
  cout << s.isempty() << endl; 
  s.pop();
  s.pop();
  s.pop();
  cout << s.isempty() << endl; 
}
