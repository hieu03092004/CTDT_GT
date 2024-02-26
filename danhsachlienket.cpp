#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node*next;
};
typedef struct node node;
//duyet danh sach lien ket
void duyet(node*head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}

}
///tao 1 mot node moi vao trong danh sach lien ket
node *makeNode(int x){
	node*newNode=(node*)malloc(sizeof(node));
	newNode->data=x;
	newNode->next=NULL;
	return newNode;
}
//them vao dau danh sach lien ket
void pushFront(node**head,int x){
	node*newNode=makeNode(x);
	newNode->next=*head;
	*head=newNode;

}
//day vao sau
void pushBack(node**head ,int x){
	node*newNode=makeNode(x);
	node*tmp=*head;
	//no phai la con tro;
	if(*head==NULL)
		*head=newNode;
	while(tmp->next!=NULL){
		tmp=tmp->next;
	}
	//luc nay minh da truy van toi not cuoi cung roi
	tmp->next=newNode;
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
			return pos;
		}
		pos++;
		head=head->next;
	}
	return pos;
}	

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	node*head=NULL;
	int n,m;
	cin>>n>>m;
	for(int i=n;i>=1;i--){
		pushFront(&head,i);
	}
	while(m--){
		int x;
		cin>>x;
		if(xl(head,x)==1){
			xoadau(&head);
			pushFront(&head,x);
		}
		else if(xl(head,x)==n){
			xoacuoi(&head);
			pushFront(&head,x);
		}
		else{
			xoagiua(&head,xl(head,x));
			pushFront(&head,x);
		}
		// duyet(head);
		// cout<<endl;
	}
	duyet(head);
}