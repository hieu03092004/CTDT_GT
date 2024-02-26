#include<bits/stdc++.h>
using namespace std;
void pre(int a[],int i,int n){
	if(i<n){
		cout<<a[i]<<" ";
		pre(a,2*i+1,n);
		pre(a,2*i+2,n);
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	pre(a,0,n);
}