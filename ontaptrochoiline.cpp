#include<bits/stdc++.h>
using namespace std;
int a[10][10],n,u,v,s,t;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
void loang(int u,int v){
	for(int k=0;k<4;k++){
		int i1=u+dx[k];
		int j1=v+dy[k];
		if(i1>=1 && i1<=n && j1>=1 && j1<=n && a[i1][j1]==0){
			a[i1][j1]=1;
			if(i1==s && j1==t)
				return;
			loang(i1,j1);
			a[i1][j1]=0;
		}
	}
}
void nhap(){
	cin>>n>>u>>v>>s>>t;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	nhap();
	loang(u,v);
	// cout<<cnt<<endl;
	if(a[s][t])
		cout<<"YES";
	else
		cout<<"NO";
}