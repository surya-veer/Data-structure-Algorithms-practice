#include<bits/stdc++.h>
using namespace std;
int main(){
    
        string exp;
        cin>>exp;
        stack<char> st;
        int len = exp.size();
        int i;
        for(i=0;i<len;i++){
            if(exp[i]=='('||exp[i]=='{'||exp[i]=='['){
                st.push(exp[i]);
            }
            else if(!st.empty()){
                if(st.top()=='['&&exp[i]==']'){
                    st.pop();
                }
                else if(st.top()=='{'&&exp[i]=='}'){
                    st.pop();
                }
                else if(st.top()=='('&&exp[i]==')'){
                    st.pop();
                }
                else{
                    break;
                }
            }
            else{
                break;
            }
        }
        if(st.empty()&&i==len){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        
        
        
    }
