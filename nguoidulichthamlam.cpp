#include<bits/stdc++.h>
using namespace std;
int c[31][31],x[50],sum=0,n;
int visited[50];
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
void in(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cout<<c[i][j]<<" ";
		cout<<endl;
	}
}
void dulich(){
	x[1]=1;
	visited[1]=1;
	int i=2;
	while(i<=n){
		int cmin=INT_MAX;
		int xi;
		for(int j=2;j<=n;j++){
			if(visited[j]==0 && cmin>c[x[i-1]][j] && c[x[i-1]][j]){
				cmin=c[x[i-1]][j];
				xi=j;
			}
		}
		sum+=c[x[i-1]][xi];
		x[i]=xi;
		visited[xi]=1;
		i++;
	}
	sum+=c[x[n]][1];
	x[i]=1;
}
void Write(){
	ofstream f;
	f.open("output.txt",ios::out);
	if(!f.is_open())
		cout<<"Can not open file";
	else{
		for(int i=1;i<=n+1;i++){
			if(i!=n+1)
				f<<"TP"<<x[i]<<" "<<"->"<<" ";
			else
				f<<"TP"<<x[i];
		
		}
		f<<endl;
		f<<"Tong chi phi la:"<<sum;
	}
	f.close();
}
int main(){
	Read();
	in();
	dulich();
	Write();
}