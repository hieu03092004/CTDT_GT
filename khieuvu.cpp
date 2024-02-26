#include<bits/stdc++.h>
using namespace std;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n,m;
	cin>>n>>m;
	int a[n],b[m];
	for(int &x:a)cin>>x;
	for(int &x:b)cin>>x;
	sort(a,a+n,greater<int>());
	sort(b,b+m,greater<int>());
	int i=0,j=0,cnt=0;
	while(i<n && j<m){
		if(a[i]>b[j]){
			cnt++;
			i++;
			j++;
		}
		else
			j++;
	}
	cout<<cnt;
}