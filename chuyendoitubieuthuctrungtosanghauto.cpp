#include<bits/stdc++.h>
using namespace std;
int pre(char c){
	if(c=='^') return 3;
	if(c=='*' || c=='/') return 2;
	if(c=='+' || c== '-') return 1;
	return 0;
}
void solve(string s){
	stack<char>st;
	string res=" ";
	for(char x:s){
		if(x=='(')
			st.push(x);
		else if(isalpha(x))
			res+=x;
		else if(x==')'){
			while(st.top()!='('){
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
	cout<<res.size()<<endl;
	cout<<res;
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
