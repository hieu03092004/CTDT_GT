#include<bits/stdc++.h>
using namespace std;
int dx[]={1,0};
int dy[]={0,1};
string path="DR";
string s;
int a[15][15],n,check=0;
void nhap(){
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
				cin>>a[i][j];
}
void Try(int i,int j){
	if(i==n && j==n){
		check=1;
		cout<<s<<endl;
	}
	for(int k=0;k<2;k++){
		int i1=i+dx[k];
		int j1=j+dy[k];
		if(i>=1 && i1<=n && j1>=1 && j1<=n && a[i1][j1]){
			a[i1][j1]=0;
			s+=path[k];
			Try(i1,j1);
			a[i1][j1]=1;
			s.pop_back();
		}
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	nhap();
	Try(1,1);
	if(check==0) cout<<"-1";
}