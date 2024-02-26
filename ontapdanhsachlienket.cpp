#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node*next;
};
typedef struct node node;
void duyet(node*head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
}
node *makeNode(int x){
	node*newNode=(node*)malloc(sizeof(node));
	// cu phap xin cap phat dong 1 not
	newNode->data=x;
	newNode->next=NULL;
	return newNode;
}
//chen dau 
 void pushFront(node**head,int x){
	node*newNode=makeNode(x);
	//dich con tro
	newNode->next=*head;
	*head=newNode;
}
// reverse linkedlist
void reverse(node*&head){
	node*current=head;
	node*next=NULL;
	node*previous=NULL;
	while(current!=NULL){
		next=current->next;
		current->next=previous;
		previous=current;
		current=next;
	}
	head=previous;
}
//chen sau vao danh sach lien ket
void pushBack(node*&head,int x){
	node*newNode=makeNode(x);
	node*tmp=head;
	//neu danh sach lien ket minh dang rong
	if(head==NULL)
		head=newNode;
	else{
		while(tmp->next!=NULL){
			tmp=tmp->next;
		}
		tmp->next=newNode;
	}
}
//xoa dau danh sach lien ket
void xoaDau(node*&head){
	//neu danh sach lien ket rong thi khong lam gi ca
	if(head==NULL)
		return;
	node*tmp=head;
	head=tmp->next;
	free(tmp);
}
void xoaCuoi(node*&head){
	//neu danh sach lien ket rong thi khong lam gi ca
	if(head==NULL)
		return ;
	node*tmp=head;
	if(tmp->next==NULL){
		//tuc la luc nay danh sach lien ket chi co 1 phan tu
		head=NULL;
		free(tmp);
	}
	else{
		while(tmp->next->next!=NULL){
			tmp=tmp->next;
		}
		node*last=tmp->next;
		free(last);
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	node*head=NULL;
	pushBack(head,1);
	pushBack(head,2);
	pushBack(head,3);
// 	duyet(head);
// 	// xoaDau(head);
// //	xoaCuoi(head);
// 	cout<<endl;
	reverse(head);

	duyet(head);
	// cout<<endl;
	
}
