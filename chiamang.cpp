#include<bits/stdc++.h>
using namespace std;
// mang co n phan tu 
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n,k,ans1=0,ans2=0;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int u1=k;
	int u2=n-k;
	if(u1>u2)
		swap(u1,u2);
	//mac dinh la u1 se la thang be hon
	sort(a,a+n);
	int i;
	for(i=0;i<u1;i++)
		ans1+=a[i];
	for(int j=i;j<n;j++)
		ans2+=a[j];
	cout<<ans2-ans1;
}