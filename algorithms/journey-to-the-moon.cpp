#include <bits/stdc++.h>
using namespace std;

#define f first 
#define s second
#define pb push_back
#define mp make_pair

typedef long long int lld;
typedef long double ldb;
vector<int> adj[100005];
bool visited[100005];
int c[100005];
int cnt = 0;
int country = 0;
void dfs(int s){
	visited[s] = true;
	cnt++;
	for(int i= 0 ;i<adj[s].size();i++){
		if(!visited[adj[s][i]]){
			dfs(adj[s][i]);
		}
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	int x,y;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x); 
	}
	long long ans=0;
	int t = n;
	for(int i=0;i<n;i++){
		if(!visited[i]){
			dfs(i);
			c[i] = cnt;
			t = t - cnt;
			ans+=cnt*t;
			//cout<<cnt<<endl;
			cnt = 0;
			//country++;
		}
	}
	cout<<ans<<endl;


}