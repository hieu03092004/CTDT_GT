#include<bits/stdc++.h>
using namespace std;
int n,s,w[50],v[50],F[1001][1001];
void Read(){
	ifstream f;
	f.open("Knapsack.txt",ios::in);
	if(!f.is_open())
		cout<<"Can not open file";
	else{
		f>>n>>s;
		for(int i=1;i<=n;i++)
			f>>v[i];
		for(int i=1;i<=n;i++)
			f>>w[i];
	}
	f.close();
}
void solve(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=s;j++)
			if(j>=w[i])
				F[i][j]=max(F[i-1][j-w[i]]+v[i],F[i-1][j]);
			else
				F[i][j]=F[i-1][j];
	}
	ofstream f;
	f.open("Knapsack-out.txt",ios::out);
	if(!f.is_open())
		cout<<"Can not open file";
	else{
		int i=n,j=s;
		while(i){
			if(F[i][j]!=F[i-1][j]){
				f<<"Vat thu:"<<i<<",gia tri:"<<v[i]<<",trong luong:"<<w[i]<<endl;
				j-=w[i];
			}
			i--;
		}
	}
	f.close();
}
int main(){
	Read();
	solve();
}