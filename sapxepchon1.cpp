#include<bits/stdc++.h>
using namespace std;
void sapxepchon(int a[],int n){
	for(int i=0;i<n-1;i++){
		int k=i;
		for(int j=i+1;j<n;j++){
			if(a[j]<a[k])
				k=j;
		}
		if(k!=i){
			swap(a[k],a[i]);
		}
		for(int l=0;l<n;l++){
			if(l==k || l==i)
				cout<<"["<<a[l]<<"]"<<" ";
			else
				cout<<a[l]<<" ";
		}
		cout<<endl;
	}
}
int main(){
//	#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	#endif
	int n;
	cin>>n;
	int a[n];
	for(int &x:a)cin>>x;
	sapxepchon(a,n);
}
