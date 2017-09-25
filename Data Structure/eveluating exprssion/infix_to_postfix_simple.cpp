//this is a simple code for converting infix(A+b*C like) to postfix(ABC*+) expression

#include<bits/stdc++.h>
using namespace std;

int HighPres(char top,char exp){

	if((top=='+'||top=='-')&&(exp=='/'||exp=='*'))
		return 0;
	else
		return 1;
}

string InfixTopPostfix(string exp){
	
	stack<char> s;
	string res;

	for(int i=0;i<exp.size();i++){

		if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'){
			while(!s.empty()&&HighPres(s.top(),exp[i])){
				res = res + s.top() +',';
				s.pop();
			}
			s.push(exp[i]);
		}
		else{

			res = res + exp[i] + ',';

		}
	}
	while(!s.empty()){
		res = res + s.top() + ',';
		s.pop();
	}

	return res;
}

int main(){
	string exp,res;
	cout<<"Write an Infix expression: ";
	cin>>exp;
	res = InfixTopPostfix(exp);
	cout<<res<<endl;
}