#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std; 
typedef struct node
{
    int value=0;
    node *next=NULL;
    node *pre=NULL;
}node;
/*node *createNode(int value)
{
    node *temp =new node;
    temp->value = value;
    temp->next = NULL;
}*/
void addnode(int value,node* &now){
	node *p;
	p=new node;
	p->pre=now;
	now->next=p;
	p->value=value;
	now=p;
}
node *findnode(node* head,int value){
	node* now=head;
	while(now->next!=head&&now->value!=value)
	now=now->next;
	return now;
}
void insertnode(int value1,int value2,node* now){
	node* pos=findnode(now,value1);
	node* p=new node;
	p->value=value2;
	p->next=pos->next;
	pos->next->pre=p;
	p->pre=pos;
	pos->next=p;
}
void deletenode(int value,node *now){
	node* pos=findnode(now,value);
	node* p=pos;
	pos->pre->next=pos->next;
	pos->next->pre=pos->pre;
	delete(p);
}
int main()
{ node* head,*now;
 head=new node;
 now=head;
    for(int i=2;i<=10;i++){
    addnode(i,now);
}	
	now->next=head;
	head->pre=now;
	node* pos;
	pos=findnode(head,5);
	insertnode(5,5,head);
/*	node* x=head;
	while(x->next!=head){
		cout<<x->value<<" ";
		x=x->next;
	}*/
	cout<<endl;
	deletenode(6,head);
/*	x=head;
		while(x->next!=head){
		cout<<x->value<<" ";
		x=x->next;
	}*/
    return 0;
}
