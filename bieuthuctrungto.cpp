#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int pre(char c){
	if(c=='*' || c=='/')
		return 2;
	else if(c=='+' || c=='-') return 1;
	return 0;
}
string infToPost(string s){
	string res="";
	stack<char>stk;
	for(int i=0;i<s.size();i++){
		if(s[i]>= '0' && s[i] <='9') res+=s[i];
		else if(s[i]=='(')
			stk.push(s[i]);
		else if(s[i]==')'){
			while(stk.size() && stk.top() !='('){
				res+=stk.top();
				stk.pop();
			}
			stk.pop();
		}
		else if(s[i]=='+' || s[i]=='-' || s[i]=='*'){
			if(res[res.size()-1]>='0' && res[res.size()-1]<='9')
				res+='#';
			while(stk.size() && pre(stk.top())>= pre(s[i])){
				res+=stk.top();
				stk.pop();
			}
			stk.push(s[i]);
		}
	}
	while(stk.size()){
		if(stk.top() !='(') 
			res+=stk.top();
		stk.pop();
	}
	return res;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	string s;
	getline(cin,s);
	s=infToPost(s);
	stack<ll>stk;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]== '+' || s[i]=='-' || s[i]=='*'){
			ll a=stk.top();
			stk.pop();
			ll b= stk.top();
			stk.pop();
			ll tmp;
			if(s[i]=='+') tmp=b+a;
			else if(s[i]=='-') tmp=b-a;
			else if(s[i]== '*') tmp=b*a;
			stk.push(tmp);
		}
		else{
			ll tmp=0;
			while(i<s.size() && s[i] >='0' && s[i]<='9'){
				tmp=10*tmp+(int)(s[i]-'0');
				i++;
			}
			if(s[i]!='#')
				i--;
			stk.push(tmp);
		}
	}
	cout<<stk.top();
}
