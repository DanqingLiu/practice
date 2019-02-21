//Stack of plates.
#include<iostream>
using namespace std;

#define THRESHOLD 4 
#define STACKNUM 3 
class SetofStack{
  private:
    int a[STACKNUM][THRESHOLD];
    int top[STACKNUM];
    int set;
    bool isfull[STACKNUM];
    bool isempty[STACKNUM];
  public:
    SetofStack(){
      set = 0;
      for(int i=0;i<STACKNUM;i++){top[i] = -1;}
      for(int i=0;i<STACKNUM;i++){isfull[i] = false;}
      for(int i=0;i<STACKNUM;i++){isempty[i] = true;}
    }
    bool push(int d);
    int pop();
    bool setisempty();
    int peek();
};

bool SetofStack::push(int d){
  if(isfull[set] == false){
    a[set][++top[set]] = d;
    if(top[set] == THRESHOLD-1){isfull[set] = true;}
  }
  else{
    cout << "Stack " << set << " is full. Put the plate to next stack." << endl;
    set++;
    a[set][++top[set]] = d;
  }
  isempty[set] = false;
}

int SetofStack::pop(){
  if(isempty[set] == true){
    cout << "Stack " << set << " is empty. Take the plate from previous stack." << endl;
    set--;
  }  
  int tmp = a[set][top[set]];
  top[set]--;
  if(top[set] < 0){isempty[set] = true;}
  return tmp;
}

bool SetofStack::setisempty(){
  if(set == -1){return true;}
  else{return false;}
}
int SetofStack::peek(){
  if(isempty[set] == true){
    set--;
  }  
  return a[set][top[set]];
}


int main(){
  SetofStack s;
  s.push(5);
  s.push(21);
  s.push(3);
  s.push(4);
  s.push(9);
  s.push(30);
  s.push(4);
  s.push(9);
  s.push(30);
  s.push(7);
  s.pop();
  s.pop();
  s.pop();
  s.pop();
  s.pop();
  s.pop();
  s.pop();
  s.pop();
  cout << s.peek() << endl;
  cout << s.setisempty() << endl; 
}
