#include<bits/stdc++.h>
using namespace std;

string Reverse(string s){
	stack<char> st;
	for(int i=0;i<s.size();i++){
		st.push(s[i]);
	}
	for(int i=0;i<s.size();i++){
		s[i] = st.top();
		st.pop();
	}
	return s;
}


int main(){
	string s;
	cin>>s;
	s = Reverse(s);
	cout<<s;
}