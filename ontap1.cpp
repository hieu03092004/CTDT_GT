#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node*next;
};
// typedef struct node node;
node*TaoNut(int x){
	node*n=new node;
	n->data=x;
	n->next=NULL;
	return n;	
}
void ChenCuoi(node*&head,int x){
	node*p=TaoNut(x);
	if(head==NULL)
		head=p;
	else{
		node*tmp=head;
		while(tmp->next!=NULL){
			tmp=tmp->next;
		}
		tmp->next=p;
		//tuc no co
	}
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
void duyet(node*head){
	node*p=head;
	while(p!=NULL){
		cout<<p->data<<" ";
		p=p->next;
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	node*head=NULL;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		chenDau(head,a[i]);
	duyet(head);
}
