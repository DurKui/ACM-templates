#include <bits/stdc++.h>
#include<cstring>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 10000
#define ll long long
using namespace std;
//Treap树，二叉搜索树，是加入优先级的二叉平衡树(根节点优先级最大，左子树所有节点的键值小于根节点，右子树所有节点的键值大于根节点的键值)
//树的形态是唯一的，依赖于每个节点的优先级,优先级随机给出
//用于返回第K大的数以及返回指定元素的排名
//以上两个功能的实现借助与一个size值记录，size指以它为根的子树的节点数
//插入、查找、删除的复杂度都是O(log(2^n))
struct Node{
ll size;
ll rank;
ll key;
Node* son[2];
int cmp(int x)const{    //比较函数，判断x再左子树还是右子树还是当前节点
    if(x==key) return -1;
    return x<key?0:1;
}
void update(){//更新size值
    size=1;
    if(son[0]!=NULL) size+=son[0]->size;
    if(son[1]!=NULL) size+=son[1]->size;
}
};
void rorate(Node* &o,int d){//核心旋转操作，d==0为左旋即逆时针，d==1为右旋
    Node* p=o->son[d^1];//p指向要旋转的那个结点
    o->son[d^1]=p->son[d];//以左旋为例子，o的右孩子为p的左孩子
    p->son[d]=o;//p的左孩子为o
    o->update();//先更新o
    p->update();//再更新p
    o=p;
}
void Insert(Node* &o, int x){
if(o==NULL)//如果o==NULL，则新建一个结点
{
    o=new Node;
    o->son[0]=o->son[1]=NULL;
    o->key=x;
    o->size=1;
    o->rank=rand();//rank为随机值
}
else {
    ll d=o->cmp(x);
    Insert(o->son[d],x);
    o->update();//从下到上更新
    if(o->rank<o->son[d]->rank)
    rorate(o,d^1);//根据rank旋转
}
}
void remove(Node* o,int x){//删除操作
if(x!=o->key){
    ll d=o->cmp(x);
    remove(o->son[d],x);
}
else {
    if(o->son[0]!=NULL&&o->son[1]!=NULL){
    ll d2=o->son[0]->rank>o->son[1]->rank;//把左结点与右结点中rank大的那个旋转到O结点
    rorate(o,d2);
    remove(o->son[d2],x);//逐渐把O结点旋转到叶子结点
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