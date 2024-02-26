#include<bits/stdc++.h>
using namespace std;
void phanHoach(int a[],int l,int r){
	int i=l-1,pivot=a[r];
	for(int j=l;j<r;j++){
		if(a[j]<=pivot){
			i++;
			swap(a[i],a[j]);
		}
	}
	i++;
	swap(a[i],a[r]);
	for(int k=0;k<=r;k++){
		if(k==i)
			cout<<"["<<a[k]<<"]"<<" ";
		else
			cout<<a[k]<<" ";
	}
}
int main(){
//	#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	#endif
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	phanHoach(a,0,n-1);
}
