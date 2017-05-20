#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	stack<char> st;
	for(int i=0;i<s.size();i++){
		if(s[i]=='{'||s[i]=='['||s[i]=='('){
			st.push(s[i]);
			// cout<<st.top();
		}
		else if(s[i]=='}'||s[i]==']'||s[i]==')'){
			if(st.top()=='{'&&s[i]=='}'){
				st.pop();
			}
			
			else if(st.top()=='['&&s[i]==']'){
				st.pop();
			}
			
			else if(st.top()=='('&&s[i]==')'){
				st.pop();
			}
			
			else{
				cout<<"Parentheses are not balanced!"<<endl;
				return 0;
				}
		}
	}
	if(st.empty())
	cout<<"Parentheses are balanced\n";
	else
		cout<<"Parentheses are not balanced!"<<endl;
}