//Rotate matrix

#include<iostream>

const int N = 3;
using namespace std;

long int **rotate(long int **image){
  long int **rotate_image = new long int*[N];
  for (int i=0;i<N;i++){
    rotate_image[i] = new long int[N];
  }
  for (int i=0; i<N; i++){
    for (int j=0; j<N; j++){
      rotate_image[j][N-1-i] = image[i][j];
    }
  }
  return rotate_image;
}

int main(){
  long int** image = new long int*[N];
  for (int i=0;i<N;i++){
    image[i] = new long int[N];
    for (int j=0;j<N;j++){
      image[i][j] = i*j + i + j;
    }
  }
  for (int i=0;i<N;i++){
    for (int j=0;j<N;j++){
      cout << image[i][j] << " ";
    }
    cout << endl; 
  }

  long int **rotate_img = rotate(image);
  for (int i=0;i<N;i++){
    for (int j=0;j<N;j++){
      cout << rotate_img[i][j] << " ";
    }
    cout << endl; 
  }
}

