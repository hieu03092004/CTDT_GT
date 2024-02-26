#include<bits/stdc++.h>
using namespace std;
void solve(int n){
	stack<int>st;
	for(int i=2;i<=sqrt(n);i++){
		while(n%i==0){
			st.push(i);
			n/=i;
		}
	}
	if(n!=1)
		st.push(n);
	while(st.size()>1){
		cout<<st.top()<<"*";
		st.pop();
	}
	cout<<st.top();
	st.pop();
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	solve(n);
}