#include<bits/stdc++.h>
using namespace std;
int t=40;
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
	f.close();
}
void solve(int a[],int n){
	int res=0,cnt=0;
	for(int i=0;i<n;i++){
		if(t>=a[i]){
			cnt++;
			res+=a[i];
			t-=a[i];
		}
	}
	ofstream f;
	f.open("output.txt",ios::out);
	if(f==NULL)
		cout<<"Can not open file";
	else{
		if(!cnt)
			f<<"-1";
		else{
		f<<cnt<<" "<<res<<endl;
		for(int i=0;i<cnt;i++)
			f<<a[i]<<" ";
		}
	}
	f.close();		
}
int main(){
	int a[100],n;
	Read(a,n);
	sort(a,a+n);
	solve(a,n);
}
