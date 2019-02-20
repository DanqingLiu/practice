//Three in one. Implement 3 stacks using one array.
#include<iostream>
using namespace std;

#define MAX 9
class FixedMultiStack{
  private:
    int a[MAX];
    int top[3];
    int stackSize;
  public:
    FixedMultiStack(){
      stackSize = MAX/3;
      top[0] = -1;
      top[1] = -1;
      top[2] = -1;
    }
    bool push(int stackNum, int d);
    int pop(int stackNum);
    bool isempty(int stackNum);
    int peek(int stackNum);
};

bool FixedMultiStack::push(int stackNum, int d){
  if(top[stackNum-1] >= stackNum * stackSize - 1){
    cout << "Stack " << stackNum << " overflow." << endl; 
    return false;
  }
  else{
    a[++top[stackNum-1]] = d; 
    return true;
  }
}
int FixedMultiStack::pop(int stackNum){
  if(top[stackNum-1] < 0){
    cout << "Stack underflow." << endl; 
    return 0;
  }
  else if(top[stackNum-1] == 3 * (stackNum - 1)){
    int tmp = a[top[stackNum-1]]; 
    top[stackNum-1] = -1; 
    return tmp;
  }
  else{return a[top[stackNum-1]--];}
}
bool FixedMultiStack::isempty(int stackNum){
  if(top[stackNum -1 ] < 0){return true;}
  else{return false;}
}
int FixedMultiStack::peek(int stackNum){
  if(top[stackNum - 1] >= 0){return a[top[stackNum-1]];}
  else{return 0;}
}


int main(){
  FixedMultiStack s;
  s.push(1,5);
  s.push(1,21);
  s.push(1,3);
  s.push(2,4);
  s.push(2,9);
  s.push(3,30);
  s.pop(1);
  cout << s.peek(2) << endl;
  cout << s.isempty(2) << endl; 
  s.pop(3);
  cout << s.isempty(3) << endl; 
}
