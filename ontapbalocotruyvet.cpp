#include<bits/stdc++.h>
using namespace std;
int v[]={4,7,10,2};
int w[]={5,2,4,4};
int m=9,n=sizeof(v)/sizeof(v[0]);
vector<pair<pair<int,int>,int>>ans;
bool cmp(pair<pair<int,int>,int>a,pair<pair<int,int>,int>b){
	auto it1=a.first;
	auto it2=b.first;
	if(it1.first> it2.first)
		return 1;
	else
		return 0;
}
void init(){
	for(int i=0;i<n;i++){
		int tmp=m/w[i];
		int k=tmp*v[i];
		ans.push_back({{k,v[i]},w[i]});
	}
	sort(ans.begin(),ans.end(),cmp);
}
int main(){
	init();
	vector<pair<pair<int,int>,int>>res;
	for(auto it:ans){
		auto v=it.first;
		int sl=v.first/v.second;
		int weight=sl*it.second;
		if(m>=weight){
			m-=weight;
			res.push_back({{v.first,sl},it.second});
		}
	}
	for(auto it:res){
		auto v=it.first;
		cout<<"Tong gia tri do vat lay duoc la:"<<v.first<<endl;
		cout<<"So luong do vat lay duoc la:"<<v.second<<endl<<"Khoi luong do vat duoc lay la:"<<it.second<<endl;
	}
}
