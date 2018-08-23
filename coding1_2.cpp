//Check permutation
//Given two strings, write a method to decide if one is a permutation of the other.

#include<iostream>
#include<string>
#include<array>

using namespace std;

int hash_function(char x){
  int index;
  index = x%128;
  return index;
}

array<int, 128> hash_table(string S){
  int n = S.length();
  array<int, 128> arr;
  for (int i=0;i<128;i++){
    arr[i] = 0;
  }
  for (int i=0;i<n;i++){
    int index = hash_function(S[i]); 
    arr[index]++;
  }
  return arr;
}

bool is_permutation(string S1, string S2){
  bool is_per = 1;
  array<int, 128> S1_table;
  array<int, 128> S2_table;
  int n1 = S1.length();
  int n2 = S2.length();
  if (n1 != n2){
    is_per = 0;
  }
  else{
    S1_table = hash_table(S1);
    S2_table = hash_table(S2);
    for (int i=0;i<n1;i++){
      if (S1_table[i] != S2_table[i]){
        is_per = 0;
        break;
      }
      else{} 
    }
  }
  return is_per;
}

int main(){
  string S1 = "cddabcdd";
  string S2 = "ddccdbd";
  if (is_permutation(S1, S2)){
    cout << "Yes." << endl;
  }
  else{
    cout << "No." << endl;
  }
}
