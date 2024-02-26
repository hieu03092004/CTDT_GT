#include<bits/stdc++.h>
using namespace std;
void Read(int a[],int &n){
	ifstream f;
	f.open("input.txt",ios::in);
	if(!f.is_open())
		cout<<"Can not open file";
	else{
		f>>n;
		for(int i=0;i<n;i++)
			f>>a[i];
	}
	f.close();
}
void solve(int a[],int n){
	vector<vector<int>>L(n);
	L[0].push_back(a[0]);
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++)
			if(a[i]> a[j] && L[i].size() < L[j].size()+1)
				L[i]=L[j];
		L[i].push_back(a[i]);
	}
	vector<int>max=L[0];
	for(vector<int>k:L)
		if(k.size()>max.size())
			max=k;
	cout<<"Do dai cua day con tang dai nhat la"<<max.size()<<endl;
	for(int i=0;i<max.size();i++)
		cout<<max[i]<<" ";
}
int main(){
	int a[100],n;
	Read(a,n);
	solve(a,n);
}
