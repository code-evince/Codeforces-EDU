#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;
vector<int> adj_list[N]; //array of vectors
bool visited[N];

void dfs(int current){
  visited[current] = true;
  for(int next_vertex : adj_list[current]){
    if(visited[next_vertex]) continue;
    dfs(next_vertex);
  }
}

int main(){

  int n,m;
  cin>>n>>m; //nodes and edges
  for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    adj_list[x].push_back(y);
    adj_list[y].push_back(x);  // this is not req if the graph is directed

  }
  int ans =0;
  for(int i=1;i<=n;i++){
    if(visited[i]) continue;
    dfs(i);
    ans++;
  }
  cout<<endl;
  cout<<"Ajacency List"<<endl;
  for(int i=1;i<n;i++){
    cout<<i<<"--> ";
    for(auto j = adj_list[i].begin();j<adj_list[i].end();j++){
      cout<<*j<<" ";
    }
    cout<<endl;
  }

  cout<<"The number of connected components are : "<<ans<<endl;


}
