//URLify

#include<iostream>
#include<string>

using namespace std;

int main(){
  string str;
  int length;
  getline(cin, str, ',');
  cin >> length;
  
  string new_str;
  new_str.push_back('"');
  for (int i=1;i<length+1;i++){
    if (str[i] == ' '){
      new_str.push_back('%');
      new_str.push_back('2');
      new_str.push_back('0');
    }
    else{
      new_str.push_back(str[i]);
    }
  }
  new_str.push_back('"');
  cout << new_str << endl;
}
