#include<bits/stdc++.h>
using namespace std;
int x[100],n,a[100],check=0;
void xl(){
	vector<int>k;
	vector<int>b;
	for(int i=1;i<=n;i++){
		if(x[i])
			k.push_back(a[i]);
		else
			b.push_back(a[i]);
	}
	int sum1=0,sum2=0;
	for(int i=0;i<k.size();i++)
		sum1+=k[i];
	for(int i=0;i<b.size();i++)
		sum2+=b[i];
	if(sum1==sum2)
		check=1;
}
void Try(int i){
	if(check) return;
	for(int j=0;j<=1;j++){
		x[i]=j;
		if(i==n)
			xl();
		else
			Try(i+1);
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	cin>>n;
	for(int i=1;i<=n;i++)
			cin>>a[i];
	Try(1);
	if(check)
		cout<<"1";
	else
		cout<<"0";
}