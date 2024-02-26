#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node*next;
};
typedef struct node node;
node *makeNode(int x){
	node*newNode=new node;
	newNode->data=x;
	newNode->next=NULL;
	return newNode;
}
void pushBack(node*&head ,int x){
	node*newNode=makeNode(x);
	node*tmp=head;
	//no phai la con tro;
	if(head==NULL)
		head=newNode;
	else{
	while(tmp->next!=NULL){
		tmp=tmp->next;
	}
	//luc nay minh da truy van toi not cuoi cung roi
	tmp->next=newNode;
	}
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
	int n;
	cin>>n;
	int a[n];
	for(int &x:a)cin>>x;
	for(int i=0;i<n;i++)
		pushBack(head,a[i]);
	duyet(head);
}	