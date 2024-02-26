#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node*left;
	node*right;
};
node*TaoNut(int x){
	node*n=new node;
	n->data=x;
	n->left=NULL;
	n->right=NULL;
	return n;
}
int NutLa(node*root){
	if(root==NULL)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return 1;
	return NutLa(root->left)+NutLa(root->right);
}
void TaoCay(node*&root,int a[],int i,int n){
	if(i<n){
		root=TaoNut(a[i]);
		TaoCay(root->left,a,2*i+1,n);
		TaoCay(root->right,a,2*i+2,n);
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	node*root=NULL;
	int a[n];
	for(int &x:a)cin>>x;
	TaoCay(root,a,0,n);
	cout<<NutLa(root);
}