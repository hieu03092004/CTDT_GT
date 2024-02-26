#include<bits/stdc++.h>
using namespace std;
int x[100],n,k,a[16],cnt=0;
vector<int>ans[15];
void xuly(){
	int sum=0;
	string res="";
	for(int i=1;i<=n;i++)
		if(x[i]==1)
			sum+=a[i];
	if(sum==k){
		for(int i=1;i<=n;i++)
			if(x[i]==1)
				ans[cnt].push_back(a[i]);
		cnt++;
	}
}
void Try(int i){
	for(int j=0;j<=1;j++){
		x[i]=j;
		if(i==n)
			xuly();
		else
			Try(i+1);
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	cin>>n>>k;
	for(int i=1;i<=n;i++)
			cin>>a[i];
	sort(a+1,a+n+1);
	Try(1);
	for(int i=cnt-1;i>=0;i--){
		cout<<"["<<" ";
		for(int j=0;j<ans[i].size();j++)
			cout<<ans[i][j]<<" ";
		cout<<"]"<<endl;
	}
}
