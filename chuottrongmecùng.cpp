#include<bits/stdc++.h>
using namespace std;
int a[15][15],check=0,n;
string s;
string path="ULRD";
vector<string>ans;
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
void nhap(){
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
}
void Try(int i,int j){
	if(i==n && j==n){
		check=1;
		ans.push_back(s);
	}
	for(int k=0;k<4;k++){
		int i1=i+dx[k];
		int j1=j+dy[k];
		if(i1>=1 && j1<=n && j1>=1 && j1<=n  && a[i1][j1]){
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
	sort(ans.begin(),ans.end());
	for(auto it:ans)
			cout<<it<<endl;
	if(check==0)cout<<"-1";
}