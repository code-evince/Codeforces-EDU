#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 200005;
vector<ll> adj_list[N]; //array of vectors
ll visited[N];
ll depth[N];
ll a[N];
ll n,k;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (ll)((x).size())
#define fr                first
#define sc                second
#define pii               pair<ll,ll>
#define rep(i,a,b)        for(ll i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

void dfs(ll v){
  visited[v] = 1;
  for(ll next_vertex : adj_list[v]){
    if(visited[next_vertex]) continue;
    depth[next_vertex]=depth[v]+1;
    dfs(next_vertex);
    visited[v]+=visited[next_vertex];
  }
}


int main(){
  ll t=1;           // t=1 in case of no testcases
  // cin>>t;           // comment out in case of no test cases
  while(t--){

    cin>>n>>k; //nodes and edges
    rep(i,1,n){
      ll x,y;
      cin>>x>>y;
      adj_list[x].push_back(y);
      adj_list[y].push_back(x);  // this is not req if the graph is directed

    }
    dfs(1);
    rep(i,1,n+1){
      a[i-1]=depth[i]-visited[i]+1;
    }
    sort(a,a+n,greater<ll>());
    ll ans=0;
    rep(i,0,k){
      ans+=a[i];
    }
    cout<<ans<<endl;
  }
}
