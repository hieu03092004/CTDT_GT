#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node*next;
};
Node*TaoNut(int x){
	Node*n=new Node;
	n->data=x;
	n->next=NULL;
	return n;
}
void ChenCuoi(Node*&head,int x){
	Node*p=TaoNut(x);
	if(head==NULL)
		head=p;
	else{
		Node*q=head;
		while(q->next!=NULL)
			q=q->next;
		q->next=p;
	}
}	
void Chuyen(Node*& head) {
    if(head->next==NULL)
    	return;
    Node*p=head;
    head=head->next;
    p->next=NULL;
    Node*q=head;
    while(q->next!=NULL)
    	q=q->next;
    q->next=p;	
}

void duyet(Node*head){
	Node*p=head;
	while(p!=NULL){
		cout<<p->data<<" ";
		p=p->next;
	}
}
int main(){
//	#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	#endif
	Node*head=NULL;
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		ChenCuoi(head,a[i]);
	Chuyen(head);
	duyet(head);
	
}
