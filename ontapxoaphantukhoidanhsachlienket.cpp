#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node*next;
};
node*TaoNut(int x){
	node*n=new node;
	n->data=x;
	n->next=NULL;
	return n;
}
void chenSau(node*&head,int x){
	node*p=TaoNut(x);
	if(head==NULL)
		head=p;
	else{
		node*q=head;
		while(q->next!=NULL)
			q=q->next;
		q->next=p;
	}
}
void duyet(node*head){
	node*p=head;
	while(p!=NULL){
		cout<<p->data<<" ";
		p=p->next;
	}

}
node*search(node*head,int x){
	node*p=head;
	while(p!=NULL){
		if(p->data==x)
			return p;
		p=p->next;
	}
	return NULL;
}
void xoa(node*&head,int x){
	node*p=search(head,x);
	if(p==NULL)
		return;
	if(head==p){
		//xoa dau;
		head=p->next;
		free(p);
		return;
	}
	node*q=head;
	while(q->next!=p){
		q=q->next;
	}
	q->next=p->next;
	free(p);
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n,x;
	cin>>n>>x;
	int a[n];
	node*head=NULL;
	for(int &x:a)cin>>x;
	for(int x:a)chenSau(head,x);
	xoa(head,x);
	duyet(head);
}