//Route between two node.
#include<iostream>
#include<queue>
using namespace std;

#define N 6
bool isRoute(int graph[N][N], int x, int y){
  queue<int> q;
  bool visited[N];
  int r;
  visited[x] = true;
  r = x;
  while(!q.empty()){
    for(int i=0;i<N;i++){
      if(graph[r][i] == 1 and visited[i] == false){
        visited[i] = true;
        q.push(i);
      }
    }
    r = q.front();
    q.pop();
  } 
}

int main(){
  int graph[N][N] = {{0,0,1,0,1,0},
           {0,1,1,0,0,0},
           {1,1,1,0,0,1},
           {0,1,0,1,0,0},
           {0,1,1,0,1,0},
           {1,1,1,0,1,1}};
  bool o;
  int x = 1;
  int y = 4;
  o = isRoute(graph,x,y);
  if(o){
    cout << "There is a path between " << x << " and " << y << endl;
  }
  else{
    cout << "No path between " << x << " and " << y << endl;
  }
}
