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
void Reverse(Node*root){
	if(root==NULL)
		return;
	Reverse(root->left);
	Reverse(root->right);
	Node*tmp=new Node;
	tmp=root->left;
	root->left=root->right;
	root->right=tmp;

}
void inorder(Node*root){
	if(root!=NULL){
		cout<<root->data;
		inorder(root->left);
		inorder(root->right);
	}
}
int main(){
	Node* root = TaoNut(1);
    root->left = TaoNut(2);
    root->right = TaoNut(3);
    root->left->left =TaoNut(4);
    root->left->right = TaoNut(5);
    Reverse(root);
    inorder(root);

}