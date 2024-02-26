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
	if(x<root->data){
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
int ChieuCao(Node*root){
	if(root==NULL)
		return 0;
	return max(1+ChieuCao(root->left),1+ChieuCao(root->right));
}
bool check(Node*&root){
	if(root==NULL)
		return 1;
	int lh=ChieuCao(root->left);
	int rh=ChieuCao(root->right);
	if(abs(lh-rh)<=1 && check(root->left) && check(root->right))
		return 1;
	return 0;
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
	if(check(root))
		cout<<"YES";
	else
		cout<<"NO";
}