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
void chenCuoi(node*&head,int x){
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
void chenDau(node*&head,int x){
	node*p=TaoNut(x);
	if(head==NULL)
		head=p;
	else{
		p->next=head;
		head=p;
	}
}
void Xoa(node*&head,int x){
	node*p=search(head,x);
	if(head==NULL)
		return;
	if(p==head){
		//day la truong hop xoa dau
		head=head->next;
		free(p);
		return;
	}
	node*q=head;
	while(q->next!=p)
		q=q->next;
	q->next=p->next;
	free(p);
}
int main(){
	 #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
     #endif
     int n,t;
    cin>>n>>t;
    node*head=NULL;
    for(int i=1;i<=n;i++)
    	chenCuoi(head,i);
    // cout<<search(head,4)->data;
    while(t--){
    	int x;
    	cin>>x;
    	Xoa(head,x);
    	chenDau(head,x);
    }
    duyet(head);
}