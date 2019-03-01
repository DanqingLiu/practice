//Implement a queue using two stack.
#include<iostream>
#include<stack>
using namespace std;

class addQueue{
  private:
    stack<int> s1;
    stack<int> s2;
  public:
    void push(int d);
    int pop();
    int peek();
    bool isempty();
};

void addQueue::push(int d){
  s1.push(d);
}

int addQueue::peek(){
  int temp;
  if(!s2.empty()){
    temp = s2.top();
  }
  else{
    while(!s1.empty()){
      s2.push(s1.top());
      s1.pop();
    }
    temp = s2.top();
  }
  return temp;
}

int addQueue::pop(){
  int temp;
  if(!s2.empty()){
    temp = s2.top();
    s2.pop();
  }
  else{
    while(!s1.empty()){
      s2.push(s1.top());
      s1.pop();
    }
    temp = s2.top();
    s2.pop();
  }
  return temp;
}

bool addQueue::isempty(){
  if(s1.empty() and s2.empty()){
    return true;
  }
  else{
    return false;
  }
}

int main(){
  addQueue q;
  q.push(3);
  q.push(5);
  q.push(7);
  cout << q.pop() << endl;
  cout << "top element: " << q.peek() << endl;
  cout << q.pop() << endl;
  cout << "top element: " << q.peek() << endl;
  q.push(12);
  cout << "top element: " << q.peek() << endl;
  q.push(21);
  cout << "top element: " << q.peek() << endl;
  cout << q.pop() << endl;
  cout << "top element: " << q.peek() << endl;
  cout << q.pop() << endl;
  cout << "top element: " << q.peek() << endl;
}
