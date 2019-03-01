//sort stack, using one temporary stack.
#include<iostream>
#include<stack>
using namespace std;

stack<int> sortStack(stack<int> s){
  int a;
  stack<int> temp;
  while(!s.empty()){
    if(temp.empty()){
      temp.push(s.top());
      s.pop();
    }
    else{
      if(s.top() >= temp.top()){
        temp.push(s.top());
        s.pop();
      }    
      else{
        a = s.top();
        s.pop();
        while(!temp.empty()){
          if(temp.top() > a){
            s.push(temp.top());
            temp.pop();
          }
          else{
            s.push(a);
            a = temp.top();
            temp.pop();
          }
        }
        s.push(a);
      }
    }
  }
  while(!temp.empty()){
    s.push(temp.top());
    temp.pop();
  }
  return s;
}

int main(){
  stack<int> s;
  s.push(7);
  s.push(3);
  s.push(12);
  s.push(2);
  s.push(5);
  stack<int> ss;
  ss = sortStack(s);
  while(!ss.empty()){
    cout << ss.top() << endl;
    ss.pop();
  }
}
