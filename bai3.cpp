#include<bits/stdc++.h>
using namespace std;
void Read(int a[],int &n){
	ifstream f;
	f.open("input.txt",ios::in);
	if(f==NULL)
		cout<<"Can not open file";
	else{
		f>>n;
		for(int i=0;i<n;i++)	
			f>>a[i];
	}	
}
int Tong(int a[],int n){
	if(n==-1)
		return 0;
	if(a[n]>0)
		return a[n]+Tong(a,n-1);
	else
		return Tong(a,n-1);
}
int main(){
	int a[100],n;
	Read(a,n);
	cout<<Tong(a,n-1);
}
