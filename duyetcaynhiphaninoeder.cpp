#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node*left;
	node*right;
	node(int x){
		data=x;
		left = right=NULL;
	}
};
// xay dung 1 cai ham co chuc nang them 1 canh vao cay
void makeRoot(node*root ,int u,int v,char c){
	if(c=='L') root->left=new node(v);
	else root -> right =new node(v);
}
void insertNode(node*root,int u,int v,int c){
	if(root==NULL)
		return;
	if(root->data==u)
		makeRoot(root,u,v,c);
	else{
		insertNode(root ->left,u,v,c);
		insertNode(root -> right,u,v,c);
	}
}
void inorde(node *root){
	if(root==NULL)
		return;
	inorde(root->left);
	cout<<root->data<<" ";
	inorde(root ->right);
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	node*root=NULL;
	int n;
	cin>>n;
	for(int i=0 ;i < n; i++){
		int u,v;
		char c;
		cin>>u>>v>>c;
		if(root==NULL){
			root=new node(u);
			makeRoot(root,u,v,c);
		}
		else{
			insertNode(root,u,v,c);
		}
	}
	inorde(root);
}