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
void insert1(Node*root,int x){
	if(x<root->data){
		//time ben cay con ben trai
		if(root->left)
			insert(root->left,x);
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
node*insert(Node*root,int key){
	if(root==NULL)
		return new Node(key);
	if(key<root->data)
		root->left=insert(root->left,key);
	else if(key>root->data)
		root->right=insert(root->right,key);
	return root;
	//de no gan nguoc	
}
//ham xoa cay nhi phan tim kiem
Node*minNode(Node*root){
	Node*tmp=root;
	while(tmp!=NULL && tmp->left!=NULL){
		tmp=tmp->left;
	}
	return tmp;
}
node*deleteNode(node*root,int key){
	if(root==NULL)
		return;
	if(key<root->data)
		root->left=deleteNode(root->left,key);
	else if(key>root->data)
		root->right=deleteNode(root->right,key);
	else{
			if(root->left==NULL){
				node*tmp=root->right;
				delete root;
				return tmp;
			}
			else if(root->right==NULL){
					node*tmp=root->left;
					delete root;
					return tmp;			
			}
			else{
				node*tmp=minNode(root->right);
				root->data=tmp->data;
				root->right=deleteNode(root->right,tmp->data);
			}
		}
		return root;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	for(int &x:a)cin>>x;
	Node*root=new Node(a[0]);
	for(int i=1;i<n;i++)
		inser1(root,a[i]);
}