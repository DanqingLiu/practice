//Zero Matrix

#include<iostream>

using namespace std;

const int M=4;
const int N=3;

int **zero_matrix(int **matrix){
  int t=0,k=0;
  int flag_i[M],flag_j[N];
  for (int i=0;i<M;i++){
    for (int j=0;j<N;j++){
      if (matrix[i][j]==0){
        flag_i[t] = i;
        flag_j[k] = j;
        t++;
        k++;
      }
    }
  }
  flag_i[t] = '\0';
  flag_j[k] = '\0';
  
  for (int i=0;i<t;i++){
    for (int j=0;j<N;j++){
      matrix[flag_i[i]][j]=0;
    }
  }
  for (int j=0;j<k;j++){
    for (int i=0;i<M;i++){
      matrix[i][flag_j[j]]=0;
    }
  }
  return matrix;
}

int main(){
  int **matrix = new int*[M];
  for (int i=0;i<M;i++){
    matrix[i] = new int[N];
    for (int j=0;j<N;j++){
      matrix[i][j]=i+j+i*j+1;
    }
  }
  matrix[0][1] = 0;
  //matrix[2][0] = 0;
  for (int i=0;i<M;i++){
    for (int j=0;j<N;j++){
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  cout << "Zero the entire row and column:" << endl;
  zero_matrix(matrix);
  for (int i=0;i<M;i++){
    for (int j=0;j<N;j++){
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

