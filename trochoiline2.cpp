#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
int a[10][10],n,u,v,s,t,check=0;
vector<pair<int,int>>tmp;
void loang(int u,int v){
	if(check==1)
		return;
	if(u==s && v==t)
		check=1;
	for(int k=0;k<4;k++){
		int i1=u+dx[k];
		int j1=v+dy[k];
		if(i1>=1 && j1>=1 &&a[i1][j1]==0 && i1<=n&& j1<=n){
			a[i1][j1]=1;
			tmp.push_back({i1,j1});
			loang(i1,j1);
			a[i1][j1]=0;
			// tmp.erase({i1,j1});			
		}
	}
}
int main(){
	 #ifndef ONLINE_JUDGE
	 freopen("input.txt", "r", stdin);
	 freopen("output.txt", "w", stdout);
	 #endif
	cin>>n>>u>>v>>s>>t;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	tmp.push_back({u,v});
	loang(u,v);
	if(check){
		cout<<tmp.size()<<endl;
			for(auto v:tmp)
				cout<<v.first<<" "<<v.second<<endl;
		}
	else
		cout<<"0";
	return 0;
}
    