#include<bits/stdc++.h>
using namespace std;
bool F[200][10000];
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n,s;
	cin>>n>>s;
	int a[n+1];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
			F[i][0]=true;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=s;j++){
			if(j>=a[i])
				F[i][j]=F[i-1][j-a[i]] || F[i-1][j];
			else
				F[i][j]=F[i-1][j];
		}
	}
	// cout<<F[n][s]<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=s;j++)
			cout<<F[i][j]<<" ";
			cout<<endl;		 
	}
	if(F[n][s]){
		cout<<"Ton tai day con co tong bang:"<<s<<endl;
		int i=n,j=s;
		while(i>0 && j>0){
			if(F[i][j] && F[i-1][j]==0){
				cout<<a[i]<<" ";
				j-=a[i];
			}
			i--;
		}

	}
	else
		cout<<"khong co day con co tong bang:"<<s;
}