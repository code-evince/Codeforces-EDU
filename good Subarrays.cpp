#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

void solve(){

  ll n;
  cin>>n;
  ll arr[n];
  string c;
  cin>>c;
  rep(i,0,n){
    arr[i]=c[i]-'0';
  }
  map<int,int> dict;

  int s=0;
  ll res=0;
  dict[0]++;
  rep(i,0,n){
    s += arr[i];
    int x = s-i-1;
    dict[x]++;
    res += dict[x]-1;

  }
  
  cout<<res<<endl;

}


int main(){
  ll t;           // t=1 in case of no testcases
  cin>>t;           // comment out in case of no test cases
  while(t--){
    solve();
  }
}
