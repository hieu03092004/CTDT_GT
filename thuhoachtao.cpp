#include<bits/stdc++.h>
using namespace std;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n,m,th=0;
	cin>>n>>m;
	int a[n+1];
	a[0]=0,a[n+1]=0;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n+1;i++){
		if(a[i-1]>=m){
			th+=m;		
		}
		else{
			th+=a[i-1];
			int z=m-a[i-1];
			//so cay toi da o ngay thu i
			if(z>a[i]){
				th+=a[i];
				a[i]=0;	
			}
			else{
				th+=z;
				a[i]-=z;
			}
		}
	}
	cout<<th;
}