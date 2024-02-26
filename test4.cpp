#include<bits/stdc++.h>
using namespace std;
int k,n,x[100],used[100],cnt=0;
void in(){
	for(int i=1;i<=k;i++)
		cout<<x[i]<<" ";
		cout<<endl;
}
//1 1
//1 2
//1 3
//1 4
//2 2
//2 3
//2 4
//3 3

void Try(int i){
	for(int j=1;j<=n;j++){
		if(!used[j]){
			used[j]=1;
			x[i]=j;
			if(i==k){
				in();
				cnt++;
			}
			else
				Try(i+1);
			used[j]=0;
		}
	}
}
int main(){
	cin>>k>>n;
	Try(1);
	cout<<cnt;
}
