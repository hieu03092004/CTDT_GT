#include<bits/stdc++.h>
using namespace std;
int c[31][31],x[50],n,used[50],sum=0;
void Read(){
	ifstream f;
	f.open("DULICH.txt",ios::in);
	if(!f.is_open())
		cout<<"Can not open file";
	else{
		f>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f>>c[i][j];
	}
	f.close();
}
void Solve(){
	int i=2;
	while(i<=n){
		int cmin=INT_MAX;
		int xi;
		for(int j=2;j<=n;j++){
			if(cmin>c[x[i-1]][j] && used[j]==0 && c[x[i-1]][j]){
				xi=j;
				cmin=c[x[i-1]][j];
			}
		}
		used[xi]=1;
		x[i]=xi;
		sum+=cmin;
		i++;
	}
	sum+=c[x[n]][1];
	x[i]=1;
}
void Write(){
	ofstream f;
	f.open("dulich_out.txt",ios::out);
	if(!f.is_open())
		cout<<"Can not open file";
	else{
		for(int i=1;i<=n+1;i++)
			if(i!=n+1)
				f<<"TP"<<x[i]<<"  -> ";
			else
				f<<"TP"<<x[i];
			f<<endl<<"Tong chi phi la:"<<sum;
	}
	f.close();
}
int main(){
	Read();
	x[1]=1;
	used[1]=1;
	Solve();
	Write();
}
