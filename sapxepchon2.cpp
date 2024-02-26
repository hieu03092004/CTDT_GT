#include<bits/stdc++.h>
using namespace std;
//thuat toan sap xep chen insertion sort
//O(N^2)
void insertionsort(int a[],int n){
	for(int i=1;i<n;i++){// do o vi tri i=0 ko thang nao dung truoc nen khong can chen
			// can n-1 buoc
		//duyet tu 0 den n-1 va chen vao
		int pos=i-1,value=a[i];
		while(pos>=0&&value<a[pos])
		//pos lon hon bang 0 vi neu truong hop be qua phan tu chen se duoc ra dau day
		{
			a[pos+1]=a[pos];
			pos--;
		}
		a[pos+1]=value;
		for(int j=0;j<n;j++){
			if(j==pos+1)
				cout<<"["<<a[j]<<"]"<<" ";
			else
				cout<<a[j]<<" ";
		}
		cout<<endl;
//		cout<<a[pos]<<" "<<pos<<endl;
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	insertionsort(a,n);
//	for(int i=0;i<n;i++)
//		cout<<a[i]<<" ";
}