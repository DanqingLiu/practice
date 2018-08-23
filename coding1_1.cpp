// Is Unique
//Implement an algorithm to determine if a string has all unique characters. 
//What if you cannot use additional data structures?

#include<iostream>
#include<string>

using namespace std;

string swap(string S, int i, int j){
  int n = S.length();
  char swap_S[n];
  for (int k=0;k<n;k++){
    if (k==i){swap_S[j] = S[i];}
    else if (k==j){swap_S[i] = S[j];}
    else {swap_S[k] = S[k];}
  }
  return swap_S;
}

string quick_sort(string S){
  int n = S.length();
  int pilot=0;
  while (pilot<n){
    int point = pilot;
    bool is_swap = 0;
    for (int i=point+1;i<n;i++){
      if (S[i] >= S[point]){//do nothing
      }
      else {
        string S1 = swap(S, point, i);
        S = S1;
        point = i;
        is_swap = 1;
      }
    }
    if (is_swap){}
    else {pilot++;}
  }
  string sort_S = S;
  return sort_S;
}

int is_unique(string S){
  quick_sort(S);
  int i = 0;
  bool is_uni = 1;
  int n = S.length();
  while (i<n){
    if (S[i]==S[i+1]){
      is_uni = 0;
      break;
    }
    else {i++;}
  }
  return is_uni;
}

int main(){
  string S = "cgfeda";
  bool is_uni = is_unique(S);
  cout << is_uni << endl;
  string S2 = "cg55da";
  bool is_uni2 = is_unique(S2);
  cout << is_uni2 << endl;
}

