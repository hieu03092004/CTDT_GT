#include<bits/stdc++.h>
using namespace std;
void LIS(int a[],int n){
	vector<vector<int>>L(n);
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[i] > a[j] && L[i].size() < L[j].size()+1)
				L[i]=L[j];
		}
		L[i].push_back(a[i]);
	}
	vector<int>max=L[0];
	for(vector<int>k:L){
		if(k.size()> max.size())
			max=k;
	}
	cout<<"Do dai cua day con tang dai nhat la:"<<max.size()<<endl;
	for(int x:max)
		cout<<x<<" ";
}
int main(){
	int a[]={6,7,2,3,9};
	int n=sizeof(a)/sizeof(a[0]);
	LIS(a,n);
}
