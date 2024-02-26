#include<bits/stdc++.h>
using namespace std;
int n,k,x[100],cnt=0;
void xuly(){
		int sum=0;
		if(x[1])
			sum++;
		bool check=true;
		for(int i=2;i<=n;i++){
			if(x[i]==0 && x[i-1]==0)
				check=false;
			if(x[i])
				sum+=x[i];
		}
		if(check && sum>=k){
			cnt++;
			ofstream f;
			f.open("Bongro.txt",ios::app);
			if(!f.is_open())
				cout<<"Can not open file";
			else{
				for(int i=1;i<=n;i++)
					if(x[i])
						f<<"x";
					else
						f<<"_";
				f<<endl;
			}
			f.close();
		}
}
void Try(int i){
	for(int j=0;j<=1;j++){
		x[i]=j;
		if(i==n)
			xuly();
		else
			Try(i+1);
	}
}
int main(){
	cin>>n>>k;
	Try(1);
	FILE*f=fopen("Bongro.txt","r+");
	if(f==NULL)
		cout<<"Can not open file";
	else{
		if(cnt==0)
			fprintf(f,"-1");
		else
			fprintf(f,"%d",cnt);
	}
	fclose(f);
}
