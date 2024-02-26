#include<bits/stdc++.h>
using namespace std;
int x[100],w[100],v[100],n,s,ans=0;
vector<int>adj[1000000];
int cnt=1;
void xuly(){
	int toltal_weight=0;
	int current_value=0;
	for(int i=1;i<=n;i++){
		if(x[i]==1){
			toltal_weight+=w[i];
			current_value+=v[i];
		}
	}
	if(toltal_weight<=s && ans <current_value){
		ans=current_value;
		for(int i=1;i<=n;i++){
			if(x[i]==1){
				adj[cnt].push_back(i);
			}
		}
		cnt++;
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
	cin>>n>>s;
	int idx=1;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		w[idx]=x;
		v[idx]=y;
		idx++;
	}
	ql(1);
	cout<<ans<<endl;
	for(int x:adj[cnt-1])
		cout<<x<<" ";
}