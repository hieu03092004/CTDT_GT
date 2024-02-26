#include<bits/stdc++.h>
using namespace std;
//tap trung do
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
	string res=" ";
	stack<char>st;
	for(char x:s){
		if(isalpha(x))
			res+=x;
		else if(x=='(')
			st.push(x);
		else if(x==')'){
			while(!st.empty() && st.top()!='('){
				res+=st.top();
				st.pop();
				}
				st.pop();
		}
		else{
			while(!st.empty() && pre(st.top())>=pre(x)){
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
	for(char x:res)
		cout<<x<<" ";

}
int main(){
//	#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	#endif
	string s;
	getline(cin,s);
	solve(s);
}
