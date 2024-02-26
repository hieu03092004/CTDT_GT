#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
   	int n,t;
   	cin>>n>>t;
   	double a[n];
   	for(int i=0;i<n;i++)
   		cin>>a[i];
   	sort(a,a+n,greater<int>());
   	// for(int i=0;i<n;i++)
   	// 	cout<<a[i]<<" ";
   	// cout<<endl;
   	int cnt=0;
   	for(int i=0;i<n;i++){
   		if(a[i]>=8.0 && t<500){
   			cout<<cnt;
   			return 0;
   		}
   		if(a[i]>=8.00 && t>=500){
   			t-=500;
   			cnt++;
   		}
   		else if(a[i]>=7.0 && t>=320 ){
   			t-=320;
   			cnt++;
   		}
   	}
   	cout<<cnt;
}
