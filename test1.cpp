#include<bits/stdc++.h>
int n,k;
int a[100],dem = 0;
int l;
void in(){
	FILE *f = fopen("Bongro.txt","a");
	if(f == NULL){
		printf("Err");
		return;
	}
		for( int i = 1 ; i <= n;i++)
		if(a[i] == 1) 
			fprintf(f,"X");
		else 
			fprintf(f,"_");
	fprintf(f,"\n");
	fclose(f);
}
void KT(){
	int sum =0;
	bool check = true;
	if(a[1] == 1) sum += a[1];
	for(int i = 2; i <= n; i++)
	{
		if(a[i] == 0 && a[i - 1] == 0)
			check = false;
		if(a[i] == 1) sum += a[i];
	}
	if(check == true && sum >= k)
	{	
		dem++;
		in();
	}
}
void Try(int i){
	for( int j = 0 ;j <= 1;j++)
	{
		a[i] = j;
		if(i == n){
			KT();
		}
		else Try(i + 1);
	}
}
int main(){
	do
	{
		printf("Nhap n: ");
		scanf("%d",&n);
		if(n < 2 || n > 20) printf("Yeu cau nhap lai\n");
	}
	while(n < 2 || n > 20);
	do
	{
		printf("Nhap k: ");
		scanf("%d",&k);
		if(k < 2 || k > n) printf("Yeu cau nhap lai\n");
	}
	while(k < 2 || k > n);
	Try(1);
	FILE *f = fopen("Bongro.txt","r+");
	if(f == NULL)
	{
		printf("Err");
		return 0;
	} 
	if(dem == 0) 
		fprintf(f,"-1");
	else
		fprintf(f,"%d\n",dem);
	fclose(f);
}
