#include<bits/stdc++.h>
using namespace std;
void R(int a[], int &n)
{
	FILE *f = fopen("input.txt","r");
	if(f == NULL)
	{
		printf("Can't open this file.");
		return;
	}
	else
	{
		fscanf(f,"%d",&n);
		for(int i = 0 ; i < n ; i++){
			fscanf(f,"%d",&a[i]);
		}		
	}
	fclose(f);
}
void Try(int a[], int n)
{
	FILE *f = fopen("output.txt","w");
	if(f == NULL )
	{
		printf("Can't not open this file");
		return;
	}
	else
	{
		int s = 0,i = 0,dem = 0;
		sort(a,a+n);
		while(i < n && s + a[i] <= 40)
		{
			s+= a[i];
			dem++;
			i++;
		}
	 	if(dem == 0) 
	 	{
	 		fprintf(f,"Khong thuc hien duoc");
	 	}
	 	else 
	 	{
	 		fprintf(f,"%d %d\n",dem,s);
	 		for(int i=0;i<dem;i++)
	 				fprintf(f,"%d ",a[i]);
	 	}	
	 }
	fclose(f);
}
int main()
{	
	int n,a[20];
	R(a,n);
	Try(a,n);
}
