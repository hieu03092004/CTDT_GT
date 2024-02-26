#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node*left,*right;
	Node(int x){
		data=x;
		left=right=NULL;
	}
};
void insert(Node*root,int x){
	if(x<root->data){
		if(root->left) insert(root->left,x);
	else
		root->left=new Node(x);
	}
	else{
		if(root->right) insert(root->right,x);
		else 
		root->right=new Node(x);
	}
}
//dem so nut
int SoNut(Node*root){
	if(root==NULL)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return 1;
	return SoNut(root->left)+SoNut(root->right);
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	int a[n];
	for(int &x:a)cin>>x;
	Node*root=new Node(a[0]);
	for(int i=1;i<n;i++)
		insert(root,a[i]);
	cout<<SoNut(root);
}