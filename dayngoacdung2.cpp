#include<bits/stdc++.h>
using namespace std;
bool check(string s){
	stack<char>st;
	for(char x:s){
		if(x=='(')
			st.push(x);
		else{
			if(st.empty())
				return false;
			st.pop();
		}
	}
	return st.empty();
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	string s;
	getline(cin,s);
	if(check(s))
		cout<<"YES";
	else
		cout<<"NO";
}