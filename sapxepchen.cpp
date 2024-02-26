#include<bits/stdc++.h>
using namespace std;
void sapxepchen(int a[],int n){
	for(int i=1;i<n;i++){
		int pos=i-1,value=a[i];
		while(pos>=0 && value<a[pos]){
			a[pos+1]=a[pos];
			pos--;
		}
		pos++;
		a[pos]=value;
		cout<<value<<" "<<pos<<endl;
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
	for(int &x:a)cin>>x;
	sapxepchen(a,n);	
}
