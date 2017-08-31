#include <bits/stdc++.h>
using namespace std;

#define f first 
#define s second
#define pb push_back
#define mp make_pair

typedef long long int lld;
typedef long double ldb;
int aa[15000];
int tree[15000];
void build(int node, int a,int b){
	if(a>b)
		return;
	if(a==b){
		tree[node] = aa[a];
		return;
	}
	build(2*node+1,a,(a+b)/2);
	build(2*node+2,(a+b)/2+1,b);


	tree[node] =  min(tree[2*node+1],tree[2*node+2]);
}

int query(int node,int a,int b,int l,int r){
	cout<<"*";
	cout<<a<<" "<<b<<endl;

	if(a>b||a>r||b<l) return INT_MAX;

	if(a>=l&&b<=r)
		return tree[node];

	int q1 = query(2*node+1,a,(a+b)/2,l,r);
	int q2 = query(2*node+2,(a+b)/2+1,b,l,r);
	return min(q1,q2);
}


int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>aa[i];
	build(0,0,n-1);
	for(int i=0;i<2*n;i++){
		cout<<tree[i]<<" ";
	}
	int l,r;
	cin>>l>>r;
	cout<<query(0,0,n-1,l,r);
}