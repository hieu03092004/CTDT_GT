#include<bits/stdc++.h>
using namespace std;
int search(int a[],int l,int r,int x){
	if(l>r)
		return -1;
	int m=(l+r)/2;
	if(a[m]==x)
		return m+1;
	if(a[m]<x)
		return search(a,m+1,r,x);
	return search(a,l,m-1,x);
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n,x;
	cin>>n>>x;
	int a[n];
	for(int &x:a)cin>>x;
	cout<<search(a,0,n-1,x);
}