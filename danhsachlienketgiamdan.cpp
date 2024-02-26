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
		while(q->next!=NULL){
			q=q->next;
		}
		q->next=p;
	}
}
bool giamdan(node*head){
		if(head->next==NULL)
			return true;
		node*p=head;
		while(p!=NULL && p->next!=NULL){
			if(p->next->data > p->data)
				return false;
			p=p->next;
		}
		return true;
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
	int n;
	cin>>n;
	node*head=NULL;
	int a[n];
	for(int &x:a)cin>>x;
	for(int x:a)chenCuoi(head,x);
	if(giamdan(head))
		cout<<"YES";
	else
		cout<<"NO";
}