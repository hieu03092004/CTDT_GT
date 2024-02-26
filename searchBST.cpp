#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data,pos;
	Node*left,*right;
	Node(int x){
		data=x;
		left=right=NULL;
	}
};
void insert(Node*root,int x){
	if(x < root->data){
		//tim ben cay con ben trai
		if(root->left) insert(root->left,x);
		else
			root->left=new Node(x);
	}
	else{
		if(root->right) 
			insert(root->right,x);
		else
			root->right=new Node(x);
	}
}
int search(Node*root,int x){
	if(root==NULL)
		return 0;
	if(root->data==x)
		return 1;
	if(x<root->data)
		return search(root->left,x);
	return search(root->right,x);
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n,x;
	cin>>n>>x;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	Node*root=new Node(a[0]);
	for(int i=1;i<n;i++)
		insert(root,a[i]);
	cout<<search(root,x);
}