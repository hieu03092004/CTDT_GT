#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll F[1001][1001];
int main(){
	#ifndef ONLINE_JUDGE
	freopen("Knapsack.txt", "r", stdin);
	freopen("Knapsack-out.txt", "w", stdout);
	#endif
	int n,s;
	cin>>n>>s;
	int w[n+1],v[n+1];
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<=n;i++)cin>>v[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=s;j++){
			if(j>=w[i])
				F[i][j]=max(F[i-1][j-w[i]]+v[i],F[i-1][j]);
			else
				F[i][j]=F[i-1][j];
		}
	}
	cout<<F[n][s];
	
}