// this code is for evaluating the postfix expressions like 2,5*12,6*+8-
#include<bits/stdc++.h>
using namespace std;

int evalualte(int x,int y,char op){
	if(op=='+')
		return x+y;
	else if(op=='-')
		return x-y;
	else if(op=='*')
		return x*y;
	else if(op=='/')
		return x/y;
}

int EvaPostfix(string exp){
	int len = exp.size();
	stack<int> st;
	for(int i=0;i<len;i++){
		if(exp[i]!=','){
			cout<<exp[i]<<"#"<<endl;
			if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'){
				int pop1,pop2;
				pop1 = st.top();st.pop();
				pop2 = st.top();st.pop();
				int res = evalualte(pop2,pop1,exp[i]);
				st.push(res);
				cout<<res<<endl;
			}
			else{
				st.push(exp[i]-'0');
			}

		}
	}
	return st.top();
}

int main(){
	string exp;
	cout<<"Enter a postfix expression: ";
	cin>>exp;
	int res;
	res = EvaPostfix(exp);
	cout<<"Value of the expression is: "<<res<<endl;
}