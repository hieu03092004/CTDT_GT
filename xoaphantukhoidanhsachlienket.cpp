#include <bits/stdc++.h>
using namespace std;
int check=false;
struct node{
	int data;
	struct node*next;
};
typedef struct node node;
node *makeNode(int x){
	node*newNode=(node*)malloc(sizeof(node));
	newNode->data=x;
	newNode->next=NULL;
	return newNode;
}
void pushBack(node**head ,int x){
	node*newNode=makeNode(x);
	node*tmp=*head;
	//no phai la con tro;
	if(*head==NULL)
		*head=newNode;
	else{
	while(tmp->next!=NULL){
		tmp=tmp->next;
	}
	//luc nay minh da truy van toi not cuoi cung roi
	tmp->next=newNode;
	}
}
void xoadau(node**head){
	if(*head==NULL)
		return;
	node*tmp=*head;
	*head=tmp->next;
	free(tmp);
}
void xoacuoi(node**head){
	if(*head==NULL)
		return;
	node*tmp=*head;
	if(tmp->next==NULL){
		*head=NULL;
		free(tmp);
	}
	while(tmp->next->next!=NULL){
		tmp=tmp->next;
	}
	node*last=tmp->next;
	free(last);
	tmp->next=NULL;
}
void xoagiua(node**head,int k){
	if(k==1)
		xoadau(head);
	else{
	node*tmp=*head;
	for(int i=1;i<k-1;i++){
		tmp=tmp->next;
	}
	node*del=tmp->next;
	tmp->next=del->next;
	free(del);
	}
}
int xl(node* head,int x){
	int pos=1;
	while(head!=NULL){
		if(head->data==x){
			check=true;
			return pos;
		}
		pos++;
		head=head->next;
	}
	return pos;
}	
void duyet(node*head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}

}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	node*head=NULL;
	int n,x;
	cin>>n>>x;
	int a[n];
	for(int &x:a)cin>>x;
	for(int i=0;i<n;i++)
		pushBack(&head,a[i]);
	if(xl(head,x)==1 && check==true)
		xoadau(&head);
	else if(xl(head,x)==n && check==true)
		xoacuoi(&head);
	else if(xl(head,x)>1 && xl(head,x)<n && check==true)
		xoagiua(&head,xl(head,x));
	duyet(head);
}