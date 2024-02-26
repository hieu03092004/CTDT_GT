#include<bits/stdc++.h>
using namespace std;
bool check(int n){
	if(n==0)
		return true;
	int r=n%10;
	if(r%2==1)
		return false;
	else
		return check(n/10);
}
void in(int n){
	for(int i=2;i<=n;i++)
		if(check(i))
			cout<<i<<" ";
}
int main(){
	int n;
	cin>>n;
//	if(check(n))
//		cout<<"YES";
//	else
//		cout<<"NO";
	in(n);
}
