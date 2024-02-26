#include<bits/stdc++.h>
using namespace std;
int Tong(int a[],int l,int r){
	if(l>r)
		return 0;
	if(l<=r){
		int m=(l+r)/2;
		return a[m]+Tong(a,l,m-1)+Tong(a,m+1,r);
	}
}
int TS(int a[],int l,int r,int x){
	if(l>r)
		return 0;
	if(l<=r){
		int m=(l+r)/2;
		if(a[m]==x)
		return 1+TS(a,l,m-1,x) +TS(a,m+1,r,x);
		else
			return TS(a,l,m-1,x)+TS(a,m+1,r,x);
	}
}
int MaxValue(int a[],int l,int r){
	if(l==r)
		return l;
	int m=(l+r)/2;
	int pos1=MaxValue(a,l,m);
	int pos2=MaxValue(a,m+1,r);
	if(a[pos1]>a[pos2])
		return pos1;
	else
		return a[pos2];
}
int Tong1(int l,int r){
	if(l>r)
		return 0;
	if(l==r)
		return l*l;
	int m=(l+r)/2;
	return m*m+Tong1(l,m-1)+Tong1(m+1,r);
}
int main(){
	int a[]={1,1,1,4};
	int n=sizeof(a)/sizeof(a[0]);
	int k;
	cin>>k;
	cout<<Tong1(1,k);
//	cout<<Tong(a,0,n-1);
//cout<<TS(a,0,n-1,1);
//cout<<MaxValue(a,0,n-1);
}
