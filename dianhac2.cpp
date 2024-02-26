#include<bits/stdc++.h>
using namespace std;
int cnt2[100001];
int cnt1[100001];
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n,m,idx=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cnt1[i]++;
	int b[m];
	for(int i=0;i<m;i++){
		int x;
		cin>>x;
		b[idx]=x;
		idx++;
		cnt2[x]++;
		cnt1[x]=0;
	}
	for(int i=idx-1;i>=0;i--){
		if(cnt2[b[i]]>0){
			cout<<b[i]<<" ";
			cnt2[b[i]]=0;
		}
	}
	for(int i=1;i<=n;i++){
		if(cnt1[i]>0)
			cout<<i<<" ";
	}	
}