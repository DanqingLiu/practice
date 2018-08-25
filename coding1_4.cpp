//Palindrome Permutation

#include<iostream>
#include<string>

using namespace std;

int isPP(string S){
  int ispp;
  int n = S.length();
  int arr[26];
  for (int i=0;i<26;i++){arr[i]=0;}
  for (int i=0;i<n;i++){
    int index;
    if (S[i]==' '){}
    else {
      if (S[i]-'a' >= 0){
        index = S[i]-'a';
      }
      else{
        index = S[i]-'a'+32;
      }
      arr[index]++;
    }
  }

  int sum=0;
  for (int i=0;i<26;i++){
    arr[i] = arr[i]%2;
    sum = sum + arr[i];
  }
  if (sum > 1){ispp = 0;}
  else {ispp = 1;}
  return ispp;
}

int main(){
  string S = "Tact Coa";
  if (isPP(S)){cout << "Yes." << endl;}
  else{cout << "No." << endl;}
}
