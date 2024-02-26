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
	//nho hon thi chac nam o cay con ben trai
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
int ChieuCao(Node*root){
	if(root == NULL) return -1;
		return max(ChieuCao(root->left)+1,ChieuCao(root->right)+1);
		
}
void postorder(Node*root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
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
	Node*root=new Node(a[0]);
	for(int i=1;i<n;i++)
		insert(root,a[i]);
	postorder(root);
	// cout<<ChieuCao(root);
}