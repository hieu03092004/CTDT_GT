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
	if(x < root->data){
		//tim ben cay con ben trai
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
bool search(Node*root,int x){
	if(root==NULL) return false;
	if(root->data==x){
		return true;
	}
	if(x<root->data)
		//tim ben cay con ben trai
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
	for(int i=0;i<n;i++){
			if(search(root,a[i]-x)){
				cout<<a[i]-x<<" "<<a[i];
				return 0;
			}
	}
	cout<<"-1";
}