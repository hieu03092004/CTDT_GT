#include<bits/stdc++.h>
using namespace std;
struct Node{
	char data;
	Node*left;
	Node*right;
};
Node*TaoNut(char x){
	Node*n=new Node;
	n->data=x;
	n->left=NULL;
	n->right=NULL;
	return n;
}
bool check(char x){
	if(x=='+' || x=='-' || x=='*' || x=='/' || x=='^')
		return 1;
	return 0;
}
int ChieuCao(Node*root){
	if(root==NULL)
		return 0;
	return max(1+ChieuCao(root->left),1+ChieuCao(root->right));
}
void solve(string s){
	stack<Node*>st;
	for(int x:s){
		if(isalpha(x)){
			Node*n=TaoNut(x);
			st.push(n);
		}
		else if(check(x)){
			Node*r=st.top();
			st.pop();
			Node*l=st.top();
			st.pop();
			Node*n=TaoNut(x);
			n->right=r;
			n->left=l;
			st.push(n);	
		}
	}
	cout<<ChieuCao(st.top());
	st.pop();	

}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	string s;
	getline(cin,s);
	solve(s);
}