#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>a,pair<int,int>b){
	if(b.second>a.second)
		return true;
	else
		return 0;
	//sort theo second tang dan
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	pair<int,int>a[n];
	for(int i=0;i<n;i++){
		cin>>a[i].first>>a[i].second;
	}
	sort(a,a+n,cmp);
	int cnt=1,current_time=a[0].second;
	for(int i=1;i<n;i++){
		if(a[i].first>current_time){
			cnt++;
			current_time=a[i].second;
		}
	}
	cout<<cnt;
}
