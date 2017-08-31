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


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
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
    priority_queue< pair<int,int> , vector <pair<int,int> > , greater<pair<int,int> > > pq;
		vector<int> dist(n+1,-1);
		pq.push(make_pair(0,src));
		vector<int> ans;
		int weight = 0,v = 0;
		while(!pq.empty()){
			int u = pq.top().second;
			int w = pq.top().first;
	        pq.pop();
				if(dist[u]==-1){
					dist[u] = w;
				    //cout<<w<<endl;
					for (int i=0;i<adj[u].size();i++){
					v = adj[u][i].first;
					weight = adj[u][i].second;
					//cout<<v<<" "<<weight<<endl;
					if(dist[v]==-1){
					    pq.push(make_pair(weight,v));
					}
				}

			}

	        
		}
		long long int a = 0;
		for(int i=0;i<=n;i++){
		    if(dist[i]!=-1)
				a+=dist[i];;
		}
    cout<<a<<endl;
    return 0;
}
