#include<bits/stdc++.h>
using namespace std;
void in(vector<int>k){
	for(int x:k)
		cout<<x<<" ";
}
void constructPrintLis(int a[],int n){
	vector<vector<int>>L(n);
	L[0].push_back(a[0]);
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[i] > a[j] && L[i].size() < L[j].size() + 1 )
				L[i]=L[j];
		}
		L[i].push_back(a[i]);
	}
	vector<int>max=L[0];
	for(vector<int>k:L){
		if(k.size() > max.size())
			max=k;
	}
	cout<<"Do dai day con tang dai nhat la:"<<max.size()<<endl;
	in(max);
}
int main(){
	int a[]={9,1,2,5,1,3,4};
	int n=sizeof(a)/sizeof(a[0]);
	constructPrintLis(a,n);
}