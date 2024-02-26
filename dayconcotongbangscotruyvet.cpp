#include<bits/stdc++.h>
using namespace std;
int F[1001][1001],s;
void init(int n){
	for(int i=0;i<=n;i++)
		F[i][0]=1;
}
void solve(int a[],int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=s;j++)
			if(j>=a[i])
				F[i][j]=F[i-1][j-a[i]] || F[i-1][j];
			else
				F[i][j]=F[i-1][j];
	}
	if(F[n][s]){
		int i=n,j=s;
		while(i>0 && j>0 ){
			if(F[i][j]==1 && F[i-1][j]==0){
				cout<<a[i]<<" ";
				j-=a[i];
			}
			i--;
		}
	}
	else
		cout<<"Khong co day con co tong bang s";
}
int main(){
	int n;
	cin>>n>>s;
	init(n);
	int a[n+1];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	solve(a,n);
}
