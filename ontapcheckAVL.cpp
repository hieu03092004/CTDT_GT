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
void insert(node*&root,int x){
	if(x<root->data){
		if(root->left)
			insert(root->left,x);
		else
			root->left=TaoNut(x);
	}
	else{
		if(root->right)
			insert(root->right,x);
		else
			root->right=TaoNut(x);		
	}
}
void inorder(node*root){
	if(root!=NULL){
		cout<<root->data<<" ";
		inorder(root->left);
		inorder(root->right);
	}
}
int chieuCao(node*root){
	if(root==NULL)
		return 0;
	return max(chieuCao(root->left)+1 ,chieuCao(root->right)+1);
}
bool isBalanced(node*root){
	if(root == NULL)
		return true;
	int lh=chieuCao(root->left);
	int rh=chieuCao(root->right);
	if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right))
		return true;
	return false;
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
	node*root=TaoNut(a[0]);
	for(int i=1;i<n;i++)
		insert(root,a[i]);
	if( isBalanced(root) )
		cout<<"YES";
	else
		cout<<"NO";
	// inorder(root);
}