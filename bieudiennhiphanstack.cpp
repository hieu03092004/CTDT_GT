#include<bits/stdc++.h>
using namespace std;
void phanTich(int n){
	stack<int>st;
	while(n){
		st.push(n%2);
		n/=2;
	}
	while(!st.empty()){
		cout<<st.top();
		st.pop();
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	if(n==0)
		cout<<n;
	else
		phanTich(n);
}