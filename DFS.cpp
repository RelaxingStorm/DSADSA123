//Depth First Search
#include <iostream>
using namespace std;
int adj[10][10], visited[10], n;

void dfs(int node){     //recursive function
  cout << node << " ";

  visited[node] = 1;

  for (int i = 0; i < n; i++){
      if ((!visited[i]) && adj[node][i]){
        dfs(i);
      }
    }
}
int main()
{
    int count = 0;
    cout<<"Enter the Number of Vertices: ";
    cin>>n;
    for(int i = 0; i<n; i++){
        visited[i]=0;
        for(int j = 0; j<n; j++){
            adj[i][j] = 0;
        }
    }
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<<"\nEnter adj["<<i<<"]"<<"["<<j<<"]: ";
            cin>>adj[i][j];
        }
    }
    dfs(0);
    for(int i = 0; i<n; i++){
        if(visited[i])
            count++;
    }
    cout<<"\ncount: "<<count;
    if(count == n){
        cout<<"\nComplete Graph";
    } else{
        cout<<"\nIncomplete Graph";
    }

    return 0;
}
