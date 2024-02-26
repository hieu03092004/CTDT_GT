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
void TaoCay(Node*&root,int x,int y){
	if(x>y)
		return;
	int m=(x+y)/2;
	root=TaoNut(m);
	TaoCay(root->left,x,m-1);
	TaoCay(root->right,m+1,y);
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
	int h;
	cin>>h;
	Node*root=NULL;
	TaoCay(root,1,pow(2,h)-1);
	duyet(root);
}