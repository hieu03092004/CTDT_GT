#include<bits/stdc++.h>
using namespace std;
void heaptify(int a[],int i,int n){
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left < n && a[left]>a[largest])
		largest=left;
	if(right<n &&  a[right]> a[largest])
		largest=right;
	if(largest!=i){
		swap(a[largest],a[i]);
		heaptify(a,largest,n);
	}
}
void heap(int a[],int n){
	for(int i=n/2-1;i>=0;i--)
		heaptify(a,i,n);
	for(int i=0;i<n;i++)
			cout<<a[i]<<" ";
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	heap(a,n);
}