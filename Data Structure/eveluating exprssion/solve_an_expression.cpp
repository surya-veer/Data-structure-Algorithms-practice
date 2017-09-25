//this is code for sove a given simple expression like 1+3*(5+6*30)

#include<bits/stdc++.h>
using namespace std;

int HighPres(char top,char exp){

	if((top=='+'||top=='-')&&(exp=='/'||exp=='*'))
		return 0;
	else
		return 1;
}

int IsOpeningParentheses(char x){
	if(x=='('||x=='{'||x=='[')
		return 1;
	else
		return 0;
}

int IsClosingParentheses(char x){
	if(x==')'||x=='}'||x==']')
		return 1;
	else
		return 0;
}

int IsOperator(char x){
	if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^'||x=='%')
		return 1;
	else
		return 0;
}
int Comma(char x){
	if(IsOpeningParentheses(x)||IsClosingParentheses(x)||IsOperator(x))
		return 1;
	else
		return 0;
}

string InfixTopPostfix(string exp){
	
	stack<char> s;
	string res;
	int comma = 0,len = exp.size();

	for(int i=0;i<len;i++){

		if(IsOperator(exp[i])){
			while(!s.empty()&&HighPres(s.top(),exp[i])&&!IsOpeningParentheses(s.top())){
				res = res +s.top() +',';
				s.pop();
			}
			s.push(exp[i]);
		}
		else if(IsOpeningParentheses(exp[i])){
			s.push(exp[i]);
		}
		else if(IsClosingParentheses(exp[i])){
			while(!s.empty()&&!IsOpeningParentheses(s.top())){
				res = res +s.top() +',';
				s.pop();
			}
			s.pop();
		}
		else{

			res = res + exp[i];
			if(Comma(exp[i+1])&&i+1<len)
				res = res + ',';
		}
	}
	while(!s.empty()){
		res = res + ',' + s.top();
		s.pop();
	}

	return res;
}

float evalualte(float x,float y,char op){
	switch(op){
		case '+' : return x + y;
		case '-' : return x - y;
		case '*' : return x * y;
		case '/' : return x / y;
		case '^' : return pow(x, y);
		default : {
			cout<<op<<" is not valid operator";
		} 
	}
}

float EvaPostfix(string exp){
	int len = exp.size();
	stack<float> st;
	for(int i=0;i<len;i++){
		if(exp[i]!=','){
			// cout<<exp[i]<<"#"<<endl;
			if(IsOperator(exp[i])){
				float pop1,pop2;
				pop1 = st.top();st.pop();
				pop2 = st.top();st.pop();
				float res = evalualte(pop2,pop1,exp[i]);
				st.push(res);
				// cout<<res<<endl;
			}
			else{
				string number;
				while(exp[i]!=','&&i<len){
					number = number + exp[i];
					i++;
				}
				// cout<<number<<'#'<<endl;
				st.push(float(atof(number.c_str())));
			}

		}
	}
	return st.top();
}
int main(){
	string exp,res;
	cout<<"Write an Infix expression: ";
	cin>>exp;
	res = InfixTopPostfix(exp);
	// cout<<res<<endl;
	float value = EvaPostfix(res);
	cout<<"The Answer is: "<<value<<endl;
}