#include<bits/stdc++.h>
int x[21],n;
using namespace std;
vector<string>ans;
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
void xuly(){
	string res="";
	for(int i=1;i<=n;i++)
		if(x[i])
			res+=")";
		else
			res+="(";
	ans.push_back(res);
}
void ql(int i){
	for(int j=0;j<=1;j++){
		x[i]=j;
		if(i==n)
			xuly();
		else
			ql(i+1);
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	cin>>n;
	ql(1);
	int cnt=0;
	for(string x:ans){
		if(check(x)){
			cout<<x<<endl;
			cnt++;
		}
	}
	cout<<cnt;
}