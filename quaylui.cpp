#include<bits/stdc++.h>
using namespace std;
int n,x[100];
void Try(int i,int sum){
	for(int j=1;j<=n;j++){
		x[i]=j;
		if(sum+j==n){
			for(int k=1;k<=i;k++)
				cout<<x[k]<<" ";
				cout<<endl;
		}
		else
			Try(i+1,sum+j);
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	cin>>n;
	Try(1,0);
}
