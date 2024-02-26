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
void TaoCay(Node*&root,int x){
	if(x < root->data){
		if(root->left)
			TaoCay(root->left,x);
		else
			root->left=TaoNut(x);
	}
	else{
		if(root->right)
			TaoCay(root->right,x);
		else
			root->right=TaoNut(x);
	}
}
void duyet(Node*root){
	if(root!=NULL){
		duyet(root->left);
		duyet(root->right);
		cout<<root->data<<" ";
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
	Node*root=TaoNut(a[0]);
	for(int i=1;i<n;i++)
		TaoCay(root,a[i]);
	duyet(root);
}