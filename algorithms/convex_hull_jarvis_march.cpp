#include <bits/stdc++.h>
using namespace std;

#define f first 
#define s second
#define pb push_back
#define mp make_pair

typedef long long int lld;
typedef long double ldb;
struct Point{
	int x,y;
};

int oriantation(Point q,Point r, Point p){ //area of tringle 
	 int area = (q.y - p.y) * (r.x - q.x) -(q.x - p.x) * (r.y - q.y);
// 	int area = (p.x)*(q.y - r.y) - (p.y)*(q.x - r.y) + (q.x)*(r.y) - (q.y)*(r.x);
	if(area==0)return 0;
	return (area>0)?1:2; 
}
vector<Point> convex(Point points[],int n){

	vector<Point> ans;
	if(n<3)
		return ans;

	int l = 0;
	//choosing left most point
	for(int i=1;i<n;i++){
		if(points[i].x < points[l].x)
			l = i;
	}
	//now initialize p as left most point 
	int p = l, q;
	do{
		ans.push_back(points[p]);
		q = (p+1)%n; //updating next point
		for(int i=0;i<n;i++){
			if(oriantation(points[p],points[i],points[q])==2){
				q = i;
			}
		}
		//adding next final element in ans
		p = q;
	}while(l!=p);

	return ans;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		Point points[n];
		for (int i = 0; i < n; ++i){
			cin>>points[i].x>>points[i].y;
		}
		vector<Point> ans = convex(points,n);
		int len = ans.size(); 
		pair<int ,int> pp[len];
			for(int i = 0;i<len;i++){
			pp[i].first = ans[i].x;
			pp[i].second = ans[i].y;
		}
		sort(pp,pp+len);
		if(len!=0)
		for(int i = 0;i<len;i++){
			cout<<pp[i].first<<" "<<pp[i].second;
			if(i!=len-1)cout<<", ";
		}
		else{
			cout<<"-1";
		}
		cout<<endl;
	}


}