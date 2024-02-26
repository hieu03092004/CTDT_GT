#include<bits/stdc++.h>
using namespace std;
int v[]={4,7,10,2};
int w[]={5,3,6,4};
int n=sizeof(v)/sizeof(v[0]);
int m=10;
vector<pair<pair<int,int>,int>>ans;
bool cmp(pair<pair<int,int>,int>a,pair<pair<int,int>,int>b){
	auto it=a.first;
	auto it1=b.first;
	if(it.first>it1.first)
			return true;
	else
		return false;
}
void init(){

	for(int i=0;i<n;i++){
		int tmp=m;
		int u=tmp/w[i];
		int k=u*v[i];
		ans.push_back({{k,v[i]},w[i]});
	}
	sort(ans.begin(),ans.end(),cmp);
}
int main(){
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif
	init();
	int res=0;
	vector<pair<pair<int,int>,int>>p;
	for(auto it:ans){
		auto v=it.first;
		cout<<v.first<<" "<<v.second<<" "<<it.second<<endl;
		int k=v.first/v.second;
		if(m>=u){
			p.push_back({{v.second,k},v.first});
			m-=u;			
		}
	}
	cout<<endl;
	for(int i=0;i<p.size();i++){
		auto it=p[i].first;
	cout<<"Gia tri do vat lay duoc la:"<<it.first<<endl<<"So do vat lay duoc la:"<<it.second<<endl;
	cout<<"tong gia tri cua do vat lay duoc la:"<<p[i].second<<endl;
	}
}