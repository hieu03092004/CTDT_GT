#include<bits/stdc++.h>
using namespace std;
int v[]={4,7,10,2};
int w[]={5,3,6,4};
int m=9,n=sizeof(v)/sizeof(v[0]);
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
		int tmp=m/w[i];
		int k=tmp*v[i];
		ans.push_back({{k,v[i]},w[i]});
	}
	//sap xep theo first tang dan
	sort(ans.begin(),ans.end(),cmp);

}
int main(){
	init();
	//mot cai vectodeluuketqua
	vector<pair<pair<int,int>,int>>res;
	for(auto it:ans){
		auto v=it.first;
		int u=v.first/v.second;
		//so luong do vat lay duoc
		int k=it.second*u;
		if(m>=k){
			res.push_back({{v.first,u},v.second});
			m-=k;
		}
	}
	for(auto it:res){
		auto v=it.first;
		cout<<"Tong gia tri lay duoc la: "<<v.first<<endl<<"So luong do vat lay duoc la: "<<v.second<<endl;
		cout<<"Gia tri do vat duoc lay la: "<<it.second<<endl;
	}
}
