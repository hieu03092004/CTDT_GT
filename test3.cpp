#include <bits/stdc++.h>
using namespace std;
int n,s, a[20], c = 0;
int x[20];
void Print(){
	for(int i = 0 ; i < c;i++)
		printf("%d ",x[i]);
	printf("\nTong so to: %d",c);
}
void DoiTien(){
	int j = 0;
	int i = 0; 
	while (s > 0 && i < n){
		if (s >= a[i]){
			x[j++] = a[i];
			s -= a[i];
			c++; 
		}
		i++;
	}
	if (s == 0)
		Print(); 
	else printf("Khong the doi duoc");
}
int main(){
	scanf("%d%d",&n,&s);
	for(int i = 0 ; i < n ;i++)
		scanf("%d",&a[i]);
	sort(a, a + n, greater<int>());
	DoiTien();
}
