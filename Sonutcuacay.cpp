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
void insert(node*&root,int x,int y){
	if(x>y)
		return;
	int m=(x+y)/2;
	root=TaoNut(m);
	insert(root->left,x,m-1);
	insert(root->right,m+1,y);
}
int SoNut(node*root){
	if(root==NULL)
		return 0;
	return 1+ SoNut(root->left) + SoNut(root->right);
}
void duyetSau(node*root){
	if(root!=NULL){
		duyetSau(root->left);
		duyetSau(root->right);
		cout<<root->data<<" ";
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int h;
	cin>>h;
	node*root=NULL;
	insert(root,1,pow(2,h)-1);
	duyetSau(root);
	// cout<<endl;
	// cout<<SoNut(root);
}