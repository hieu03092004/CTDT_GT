#include<bits/stdc++.h>
using namespace std;
int cnt[1000006];
int n,t;
void solve(int a[],int b[],int n){
	int cnt1=0;
	for(int i=0;i<n;i++){
		if(t>=b[i]){
			cnt[b[i]]=1;
			t-=b[i];
			cnt1++;
		}
	}
	if(cnt1==0)
		cout<<"-1";
	else{
		for(int i=0;i<n;i++)
			if(cnt[a[i]])
				cout<<a[i]<<" ";
			cout<<endl<<"Tong so to la: "<<cnt1;

	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	cin>>n>>t;
	int a[n],b[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b,b+n,greater<int>());
	solve(a,b,n);
}