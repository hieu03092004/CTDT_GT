#include<bits/stdc++.h>
using namespace std;
void heaptify(int a[],int n,int i){
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n && a[l]>a[largest])
		largest=l;
	if(r<n && a[r]> a[largest])
		largest=r;
	if(largest!=i){
		swap(a[i],a[largest]);
		heaptify(a,n,largest);
	}
}
void heapsort(int a[],int n){
	for(int i=n/2-1;i>=0;i--)
		heaptify(a,n,i);

	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
//	cout<<endl;
//	
//	for(int i=n-1;i>=0;i--){
//		swap(a[i],a[0]);
//		heaptify(a,i,0);
//		for(int j=0;j<i;j++)
//			cout<<a[j]<<" ";
//		cout<<endl;
//	}

}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	int a[n];
	for(int &x:a)cin>>x;
	heapsort(a,n);
}
