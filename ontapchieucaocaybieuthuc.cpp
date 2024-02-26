#include<bits/stdc++.h>
using namespace std;
struct node{
	char data;
	node*left;
	node*right;
};
node*TaoNut(char x){
	node*n=new node;
	n->data=x;
	n->left=NULL;
	n->right=NULL;
	return n;
}
int chieucao(node*root){
	if(root==NULL)
		return 0;
	return max(chieucao(root->left)+1,chieucao(root->right)+1);
}
bool check(char x){
	if(x!=' ')
		return true;
	return false;
}
void solve(string s){
	stack<node*>st;
	for(char x:s){
		if(isalpha(x)){
			node*n=TaoNut(x);
			st.push(n);
		}
		else if(check(x)){
			node*r=st.top();
			st.pop();
			node*l=st.top();
			st.pop();
			node*q=TaoNut(x);
			q->left=l;
			q->right=r;
			st.push(q);
		}
	}
	cout<<chieucao(st.top());
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