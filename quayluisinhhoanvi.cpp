#include<bits/stdc++.h>
using namespace std;
int n,x[100];
bool used[100];
//de luu cau hinh
void in(){
	for(int i=1;i<=n;i++)
		cout<<x[i]<<" ";
	cout<<endl;
}
void Try(int i){
	for(int j=1;j<=n;j++){
		if(used[j]==0){
			x[i]=j;
			used[j]=1;
			if(i==n)
				in();
			else
			Try(i+1);
		//backtrack
			used[j]=0;
		}
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	cin>>n;
	Try(1);
}