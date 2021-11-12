#include<bits/stdc++.h>
#include<iostream>
using namespace std;
struct node{
	int val;
	node* next;
	node* pre;
};
int main(){
	int n,m;
	cin >> n>> m;
	node *head,*p,*now,*q;
	head=new node;
	head->val=1;head->next=NULL;
	now=head;
	for(int i=2;i<=n;i++)
	{	p = new node;
	p->val=i;p->next=NULL;
	p->pre=now;
	now->next=p;
	now=p;	
	}
	now->next=head;
	head->pre=now;
	now=head;
	while((n--)>1){
		for(int i=1;i<m;i++)
		now=now->next;
		cout<<now->val<<" ";
		q=now->next;
		now->pre->next=now->next;
		now->next->pre=now->pre;
		delete now;
		now=q;
	}
	cout<<now->val<<endl;
	delete now;
	return 0;
}
