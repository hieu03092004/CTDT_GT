#include<bits/stdc++.h>
using namespace std;
int a[101][101],u,v,n,m,cnt=0;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
void loang(int u,int v){
	if(a[u][v]==0){
		cnt++;
		a[u][v]=1;
	}
	for(int k=0;k<4;k++){
		int i1=u+dx[k];
		int j1=v+dy[k];
		if(i1>=1 && i1<=n && j1>=1 && j1<=m && a[i1][j1]==0){
			cnt++;
			a[i1][j1]=1;
			loang(i1,j1);
			}
	}
}
void nhap(){
	cin>>n>>m>>u>>v;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
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
	cout<<cnt;
}