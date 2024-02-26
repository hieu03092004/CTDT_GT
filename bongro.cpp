#include<bits/stdc++.h>
using namespace std;
int n,k,idx=0;
int x[100];
vector<string>adj[1000001];
void xuly(){
	int sum=0;
	bool check=true;
	if(x[1])
		sum+=x[1];
	for(int j=2;j<=n;j++){
		if(x[j]==0 && x[j-1]==0)
			check=false;
		if(x[j])
			sum+=x[j];
	}
	if(sum>=k && check==true){
		string res="";
		for(int i=1;i<=n;i++){
			if(x[i])
				res+="X";
			else
				res+="_";
		}
		adj[idx].push_back(res);
		idx++;
	}

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
	cin>>n>>k;
	ql(1);
	cout<<idx<<endl;
	for(int i=0;i<idx;i++){
		for(int j=0;j<adj[i].size();j++)
			cout<<adj[i][j];
		cout<<endl;
	}
}