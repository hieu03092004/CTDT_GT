#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct Job
{
	int st,ed;
	ll profit;
};
bool cmp(Job a,Job b){
	return a.ed<b.ed;
}
int firstpos(Job a[],int i,int x){
	int l=1,r=i-1,res=-1;
	while(l<=r){
		int m=(l+r)/2;
		if(a[m].ed<=x){
			res=m;
			l=m+1;
		}
		else
			r=m-1;
	}
	return res;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	Job a[n+1];
	ll F[n+1]={0};
	for(int i=1;i<=n;i++)
		cin>>a[i].st>>a[i].ed>>a[i].profit;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		int t=firstpos(a,i,a[i].st-1);
		if(t==-1)
			F[i]=max(a[i].profit+0,F[i-1]);
		else
			F[i]=max(a[i].profit+F[t],F[i-1]);
	}
	cout<<F[n];
}