#include<bits/stdc++.h>
using namespace std;
int x[100],n,k,s,cnt=0;
void xuly(){
	int sum=0;
	for(int i=1;i<=k;i++)
		sum+=x[i];
	if(sum==s)
		cnt++;
}	
void Try(int i){
	for(int j=x[i-1]+1;j<=n-k+i;j++){
		x[i]=j;
		if(i==k){
			xuly();
		}
		else
			Try(i+1);
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	cin>>n>>k>>s;
	Try(1);
	cout<<cnt;
}
