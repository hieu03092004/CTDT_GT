#include<bits/stdc++.h>
using namespace std;
int c[31][31],res[50],x[50],n,used[50],cmin=INT_MAX;
int ans=INT_MAX,dis=0;
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
int Min(int a,int b){
	if(a<b)
		return a;
	else
		return b;
}
void xuly(){
	int tmp=dis+c[x[n]][1];
	if(ans>tmp){
		int i;
		for(i=1;i<=n;i++)
			res[i]=x[i];
		res[i]=1;
		ans=tmp;	
	}
}
void Try(int i){
	for(int j=2;j<=n;j++){
		if(used[j]==0){
			x[i]=j;
			used[j]=1;
			dis+=c[x[i-1]][x[i]];
			if(i==n)
				xuly();
			else if(dis+(n-i+1)*cmin<ans)
				Try(i+1);
			used[j]=0;
			dis-=c[x[i-1]][x[i]];
		}
	}
}
void Write(){
	ofstream f;
	f.open("dulich_out.txt",ios::out);
	if(!f.is_open())
		cout<<"Can not open file";
	else{
		for(int i=1;i<=n+1;i++)
			if(i!=n+1)
				f<<"TP "<<res[i]<<"-> ";
			else
				f<<"TP"<<res[i];
		f<<endl<<"Tong chi phi la:"<<ans;
	}
	f.close();
}
int main(){
	Read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(c[i][j])
				cmin=Min(c[i][j],cmin);
	used[1]=1;
	x[1]=1;
	Try(2);
	Write();
//	for(int i=1;i<=n+1;i++)
//		cout<<res[i]<<" ";
}
