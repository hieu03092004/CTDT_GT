#include<bits/stdc++.h>
using namespace std;
int pre(char x){
	if(x=='^')
		return 3;
	if(x=='*' || x=='/')
		return 2;
	if(x=='+' || x=='-')
		return 1;
	return 0;
}
void solve(string s){
	string res="";
	stack<char>st;
	for(int x:s){
		if(x=='(')
			st.push(x);
		else if(isalpha(x))
			res+=x;
		else if(x==')'){
			while(!st.empty() && st.top()!='('){
				res+=st.top();
				st.pop();
			}
			st.pop();
		}
		else{
			while(!st.empty() && pre(st.top())>= pre(x)){
				res+=st.top();
				st.pop();
			}
			st.push(x);
		}
	}
	while(!st.empty()){
		res+=st.top();
		st.pop();
	}
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<" ";
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	string s;
	getline(cin,s);
	solve(s);
}