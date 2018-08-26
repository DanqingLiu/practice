//One Away

#include<iostream>
#include<string>

using namespace std;

bool is_edit(string S1, string S2){
  int n1 = S1.length();
  int n2 = S2.length();
  bool is_edit = 1;
  if (n1-n2>1 || n1-n2>1){
    is_edit = 0;
  }
  else if (n1==n2){
    int i=0;
    int diff=0;
    while(i<n1){
      if(S1[i]==S2[i]){
        i++;
      }
      else{
        diff++;
        i++;
      }
      if(diff>1){
        is_edit=0;
        break;
      }
    }
  }
  else{
    if(n1-n2==1){
      int i=0,j=0;
      while(i<n2){
        if(S1[i]==S2[j]){
          i++;
          j++;
        }
        else{
          i++;
        }
        if(i-j>1){
          is_edit=0;
          break;
        }
      }
    }
    else{
      int i=0,j=0;
      while(i<n1){
        if(S1[i]==S2[j]){
          i++;
          j++;
        }
        else{
          j++;
        }
        if(j-i>1){
          is_edit=0;
          break;
        }
      }
    }
  }
  return is_edit;
}

int main(){
  string S1 = "pale";
  string S2 = "bae";
  if (is_edit(S1,S2)){
    cout << "Yes." << endl;
  }
  else{
    cout << "No." << endl;
  }
}
