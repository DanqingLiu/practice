//String Compression

#include<iostream>
#include<string>

using namespace std;

string compress(string S, int n){
  int i=0, flag=0;
  string new_S;
  new_S.push_back(S[0]);
  while (i<n){
    if (S[i+1]==S[i]){
      i++;
    }
    else{
      int num = i-flag+1;
      string nums = to_string(i-flag+1);
      for (int t=0;t<nums.length();t++){
        new_S.push_back(nums[t]);
      }
      i++;
      flag = i;
      new_S.push_back(S[i]);
      
    }
  }
  return new_S;
}

int main(){
  string S = "aabcccccaaa";
  int n = S.length();
  string newS = compress(S, n);
  cout << newS << endl;
}
