#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct node{
	int data;
	node *left;
    node *right;
};
node *makeNode(int x){
	node *newNode = new node;
	newNode -> data = x;
	newNode -> left = NULL;
	newNode -> right = NULL;
	return newNode;
}
void insert(node *&root, int x, int y){
	if(x > y) return;
	int m = (x+y)/2;
	root = makeNode(m);
    insert(root->left,x,m-1);
    insert(root->right,m+1,y);
}

void duyet(node *root){
	if(root == NULL) return;
	duyet(root->left);
	duyet(root->right);
	cout << root->data << " ";
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	node *root = NULL;
	int h; cin >> h;
	int n = pow(2,h) - 1;
	insert(root,1,n);
	duyet(root);
}