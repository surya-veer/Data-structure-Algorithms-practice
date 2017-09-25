#include <bits/stdc++.h>
using namespace std;

#define f first 
#define s second
#define pb push_back
#define mp make_pair

typedef long long int lld;
typedef long double ldb;
int a[7]={1 ,3 ,9 ,8 ,2 ,7, 5};
int Partition(int start,int end){
	int pivot = a[end];
	int pindex = start;
	for(int i=start;i<end;i++){
		if(a[i]<=pivot){
			swap(a[i],a[pindex]);
			pindex++;
		}

		
	}

	swap(a[end],a[pindex]);
	return pindex;
}
void QuickSort(int start,int end){
	if(start<end){
		int pivot = Partition(start,end);
		QuickSort(start,pivot-1);
		QuickSort(pivot+1,end);
	}
	for(int i=0;i<7;i++){
			cout<<a[i]<<" ";
		}cout<<endl;
}



int main(){
	QuickSort(0,6);
	
	for(int i=0;i<7;i++){
		cout<<a[i]<<" ";
	}
}