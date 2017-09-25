#include <bits/stdc++.h>
using namespace std;

#define f first 
#define s second
#define pb push_back
#define mp make_pair
#define INF 999999999;

typedef long long int lld;
typedef long double ldb;

typedef pair<int,int> ipair;




int main(){
	int T;
	cin>>T;
	while(T--){
		int n,m;
		cin>>n>>m;
		vector<pair<int,int> > adj[5000];
		for(int i=0;i<m;i++){
			int u,v,w;
			cin>>u>>v>>w;
			adj[u].push_back(make_pair(v,w));
			adj[v].push_back(make_pair(u,w));
		}
		int src;
		cin>>src;
		priority_queue< ipair, vector <ipair> , greater<ipair> > pq;
		vector<int> dist(n+1,-1);
		pq.push(mp(0,src));
		while(!pq.empty()){
			int u = pq.top().second;
			int w = pq.top().first;
	        pq.pop();

				if(dist[u]==-1){
					dist[u] = w;
					for (int i=0;i<adj[u].size();i++){
					int v = adj[u][i].first;
					int weight = adj[u][i].second;
					//cout<<v<<" "<<weight<<endl;
					if(dist[v]==-1){
						pq.push(make_pair(weight+w,v));
					}
				}

			}

	        
		}
		for(int i=1;i<=n;i++){
				if(i!=src)
					cout<<dist[i]<<" ";
		}
	    cout<<endl;
	}
}