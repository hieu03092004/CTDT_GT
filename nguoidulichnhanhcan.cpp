#include<bits/stdc++.h>
using namespace std;
int n,cmin=INT_MAX,ans=INT_MAX,dis=0;
int c[31][31],visited[50],x[50];
int res[50];//de luu ket qua
void Read(){
	ifstream f;
	f.open("input.txt",ios::in);
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
void xuly(){
	int tmp=dis+c[x[n]][1];
	if(ans>tmp){
		ans=tmp;
		int i;
		for(i=1;i<=n;i++)
			res[i]=x[i];
		res[i]=1;
	}
}
void Try(int i){
	for(int j=2;j<=n;j++){
		if(visited[j]==0){
			x[i]=j;
			visited[j]=1;
			dis+=c[x[i-1]][x[i]];
			if(i==n)
				xuly();
			else if(ans>dis+(n-i+1)*cmin)
				Try(i+1);
			visited[j]=0;
			dis-=c[x[i-1]][x[i]];
		}
	}
}
void Write(){
	ofstream f;
	f.open("output.txt",ios::out);
	if(!f.is_open())
		cout<<"Can not open file";
	else{
		for(int i=1;i<=n+1;i++){
			if(i!=n+1)
				f<<"TP"<<res[i]<<" -> ";
			else
				f<<"TP"<<res[i];
		}
		f<<endl<<"Tong chi phi la:"<<ans;
	}
}
int main(){
	Read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(c[i][j])
				cmin=min(c[i][j],cmin);
	visited[1]=true;
	x[1]=1;
	Try(2);
	Write();
}