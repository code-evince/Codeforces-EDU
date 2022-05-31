#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;
vector<int> adj_list[N]; //array of vectors
bool visited[N];




int height_dfs(int current){
  int max_height=0;
  visited[current] = true;

  if((adj_list[current]).empty()) return 0;             // if the current node has no child return 0
  for(int next_vertex : adj_list[current]){
    if(visited[next_vertex]) continue;
    max_height = max(max_height,height_dfs(next_vertex));
  }
  cout<<"Current Vertex : "<<current<<" Returns:  "<<max_height+1<<endl;
  return max_height+1;                                // successfully explored the child so count it
}


int main(){

  int n;
  cin>>n;
  int x;
  for(int i=0;i<n;i++){
    cin>>x;
    if(x==-1) adj_list[0].push_back(i+1);
    else adj_list[x].push_back(i+1);

  }

  for(int i=0;i<=n;i++){
    cout<<i<<"--> ";
    for(auto j = adj_list[i].begin();j<adj_list[i].end();j++){
      cout<<*j<<" ";
    }
    cout<<endl;
  }

  int ans = 0;
  for(int i=0;i<n;i++){
    if(!visited[i]){
      ans = max(height_dfs(i),ans);
    }
  }
  cout<<ans<<endl;
  cout<<endl;
  for(int i=0;i<=n;i++){
    cout<<i<<":"<<visited[i]<<"  ";
  }


}
