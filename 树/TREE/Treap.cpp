#include <bits/stdc++.h>
#include<cstring>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 10000
#define ll long long
using namespace std;
//Treap�����������������Ǽ������ȼ��Ķ���ƽ����(���ڵ����ȼ�������������нڵ�ļ�ֵС�ڸ��ڵ㣬���������нڵ�ļ�ֵ���ڸ��ڵ�ļ�ֵ)
//������̬��Ψһ�ģ�������ÿ���ڵ�����ȼ�,���ȼ��������
//���ڷ��ص�K������Լ�����ָ��Ԫ�ص�����
//�����������ܵ�ʵ�ֽ�����һ��sizeֵ��¼��sizeָ����Ϊ���������Ľڵ���
//���롢���ҡ�ɾ���ĸ��Ӷȶ���O(log(2^n))
struct Node{
ll size;
ll rank;
ll key;
Node* son[2];
int cmp(int x)const{    //�ȽϺ������ж�x���������������������ǵ�ǰ�ڵ�
    if(x==key) return -1;
    return x<key?0:1;
}
void update(){//����sizeֵ
    size=1;
    if(son[0]!=NULL) size+=son[0]->size;
    if(son[1]!=NULL) size+=son[1]->size;
}
};
void rorate(Node* &o,int d){//������ת������d==0Ϊ��������ʱ�룬d==1Ϊ����
    Node* p=o->son[d^1];//pָ��Ҫ��ת���Ǹ����
    o->son[d^1]=p->son[d];//������Ϊ���ӣ�o���Һ���Ϊp������
    p->son[d]=o;//p������Ϊo
    o->update();//�ȸ���o
    p->update();//�ٸ���p
    o=p;
}
void Insert(Node* &o, int x){
if(o==NULL)//���o==NULL�����½�һ�����
{
    o=new Node;
    o->son[0]=o->son[1]=NULL;
    o->key=x;
    o->size=1;
    o->rank=rand();//rankΪ���ֵ
}
else {
    ll d=o->cmp(x);
    Insert(o->son[d],x);
    o->update();//���µ��ϸ���
    if(o->rank<o->son[d]->rank)
    rorate(o,d^1);//����rank��ת
}
}
void remove(Node* o,int x){//ɾ������
if(x!=o->key){
    ll d=o->cmp(x);
    remove(o->son[d],x);
}
else {
    if(o->son[0]!=NULL&&o->son[1]!=NULL){
    ll d2=o->son[0]->rank>o->son[1]->rank;//���������ҽ����rank����Ǹ���ת��O���
    rorate(o,d2);
    remove(o->son[d2],x);//�𽥰�O�����ת��Ҷ�ӽ��
    }
    else
    {    Node* u=o;
        if(o->son[0]==NULL) o=o->son[1];
        else o=o->son[0];
        delete u;
    }
}
if(o!=NULL) o->update();
}
int kth(Node* o,int k){
    if(o==NULL||k<0||k>o->size) return 0;
    ll s=o->son[1]==NULL?0:o->son[1]->size;
    if(s+1==k) return o->key;
    if(k<=s) return kth(o->son[1],k);
    else
    {
        ll tmp=kth(o->son[0],k-s-1);
    }
}
int find(Node* o,ll x){
    if(o==NULL) return -1;
    ll d=o->cmp(x);
    if(d==-1) return o->son[1]==NULL?1:o->son[1]->size+1;
    else if(d==1) return find(o->son[1],x);
    else
    {
        ll tmp=find(o->son[0],x);
        if(tmp==-1) return -1;
        else return o->son[1]==NULL?tmp+1:tmp+o->son[1]->size+1;  
    }
}
int main(){
    return 0;
}