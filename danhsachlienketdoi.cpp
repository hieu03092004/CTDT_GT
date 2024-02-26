#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node*next;
	node*prev;
};
node*TaoNut(int x){
	node*n=new node;
	n->data=x;
	n->next=NULL;
	n->prev=NULL;
	return n;
}
void chenDau(node*&head,int x){
	node*n=TaoNut(x);
	if(head==NULL)
		head=n;
	else{
	n->next=head;
	head->prev=n;
	head=n;
	}
}
void duyet(node*head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
}
void chenCuoi(node*&head,int x){
	node*n=TaoNut(x);
	if(head==NULL)
		head=n;
	else{
		node*p=head;
		while(p->next!=NULL)
			p=p->next;
		p->next=n;
		n->prev=p;
	}
}
void chuyen(node*&head,int n){
	if(head==NULL|| head->next==NULL)
		return;
	node*first=head;
	node*last=head;
	while(last->next!=NULL){
		last=last->next;
	}
	for(int i=1;i<=n/2;i++){
		int tmp=first->data;
		first->data=last->data;
		last->data=tmp;
		first=first->next;
		last=last->prev;
	}

}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	node*head=NULL;
	int n;
	cin>>n;
	int a[n];
	for(int &x:a)cin>>x;
	for(int x:a)chenCuoi(head,x);
	chuyen(head,n);
	duyet(head);
}