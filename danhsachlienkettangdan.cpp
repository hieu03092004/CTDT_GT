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
		node*tmp=head;
		while(tmp->next!=NULL){
			tmp=tmp->next;
		}
		tmp->next=p;
	}

}
void duyet(node*head){
	node*p=head;
	while(p!=NULL){
		cout<<p->data<<" ";
		p=p->next;
	}
}
bool tangDan(node*head){
	if(head->next==NULL)
		return true;
	node *p=head;
	while(p!=NULL && p->next!=NULL){
		if(p->next->data < p->data)
			return false;
		p=p->next;
	}
	return true;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	int a[n];
	node*head=NULL;
	for(int &x:a)cin>>x;
	for(int x:a) chenCuoi(head,x);
	// 	duyet(head);
	// cout<<endl;
	if(tangDan(head))
		cout<<"YES";
	else
		cout<<"NO";
}