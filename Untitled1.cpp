#include<bits/stdc++.h>
using namespace std;
int a[100];
void input(int &n){
	do{
		cout<<"nhap 2<n<20:";
		cin>>n;
	}
	while(!(n>2 && n<20));
	for(int i=0;i<n;i++){
		cout<<"Nhap a"<<"["<<i<<"]"<<"="<<endl;
		cin>>a[i];
	}
}
int main(){
	int n;
	input(n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	
}
