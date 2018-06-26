#include <bits/stdc++.h>

using namespace std;

string distance(int **graph, int N, int O, int D);

int main(){
  int N, E;

  cin >> N >> E;

  while(N != 0 or E != 0){
    int **graph = new int*[N];
    for(int i = 0; i < N; ++i){
      graph[i] = new int[N];
      for(int j = 0; j < N; j++){
      graph[i][j] = INT_MAX;
      }
    }

    int X, Y, H;
    while(E--){
      cin >> X >> Y >> H;

      if(graph[Y-1][X-1] == INT_MAX)
        graph[X-1][Y-1] = H;
      else{
        graph[X-1][Y-1] = 0;
        graph[Y-1][X-1] = 0;
      }
    }

    int cases;

    cin >> cases;
    while(cases--){
      int O, D;
      cin >> O >> D;
      cout << distance(graph, N, O-1, D-1) << endl;
    }
    cout << endl;
    cin >> N >> E;
  }
  cout<< endl;
  return 0;
}

string distance(int **graph, int N, int O, int D){
  int *dist = new int[N];
  bool *visited = new bool[N];
  int current;

  for(int i = 0; i < N; i++){
    visited[i] = false;
    dist[i] = INT_MAX;
  }

  dist[O] = 0;

  for(int i = 0; i < N; i++){

    if(visited[D]){
      break;
    }
    
    int min = INT_MAX;

    for (int j = 0; j < N; j++){
      if (not visited[j] and dist[j] <= min){
        min = dist[j];
        current = j;
      }
    }

    if(min == INT_MAX){
      break;
    }

    visited[current] = true;

    for(int j = 0; j < N; j++){
      if(graph[current][j] == INT_MAX) continue;
      int distance = min + graph[current][j];
      if(distance < dist[j]){
        dist[j] = distance;
      }
    }
  }
  
  if(dist[D] == INT_MAX){
    return "Nao e possivel entregar a carta";
  } else{
    return to_string(dist[D]);
  }
}
