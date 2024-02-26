#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int mod=1e4;
ll pin_pow(ll a,ll b){
	if(b==0)
		return 1;
	ll X=pin_pow(a,b/2);
	if(b%2==0)
	return (X%mod) * (X%mod) %mod;
	else
		return  ( (X%mod) * (X%mod) %mod) *(a%mod) % mod;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ll a,b;
	cin>>a>>b;
	cout<<pin_pow(a,b);
}