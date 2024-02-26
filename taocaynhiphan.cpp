#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node*left;
	Node*right;
};
Node*TaoNut(int x){
	Node*n=new Node;
	n->data=x;
	n->left=NULL;
	n->right=NULL;
	return n;
}
void TaoCay(Node*&root,int a[],int i,int n){
	if(i<n){
		root=TaoNut(a[i]);
		TaoCay(root->left,a,2*i+1,n);
		TaoCay(root->right,a,2*i+2,n);
	}
}
void duyet(Node*root){
	if(root!=NULL){
		cout<<root->data<<" ";
		duyet(root->left);
		duyet(root->right);
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	Node*root=NULL;
	TaoCay(root,a,0,n);
	duyet(root);
}