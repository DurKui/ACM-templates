#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//�߶���ģ��2 �����޸ģ������ѯ
struct Tree{
    ll l,r;
    ll sum=0;
    ll lz=0;
}tree[1000005];
ll in[1000005];
ll n,m;
void scan()
{
   scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++)
    scanf("%lld",&in[i]);
}
 void build(int i,int l,int r){//�ݹ齨��
    tree[i].l=l;tree[i].r=r;
    if(l==r){//�������ڵ���Ҷ�ӽڵ�
        tree[i].sum=in[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(i*2,l,mid);//�ֱ�����������������
    build(i*2+1,mid+1,r);
    tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;//�ղ����Ƿ��ֵ�����return ;
}
void push_down(int i)
{
    if(tree[i].lz!=0)
    {
        tree[i*2].lz+=tree[i].lz;//���Ҷ��ӷֱ���ϸ��׵�lz
        tree[i*2+1].lz+=tree[i].lz;
        int  mid=(tree[i].l+tree[i].r)/2;
        tree[i*2].sum+=tree[i].lz*(mid-tree[i*2].l+1);//���ҷֱ���ͼ�����
        tree[i*2+1].sum+=tree[i].lz*(tree[i*2+1].r-mid);
        tree[i].lz=0;//����lz����
    }
    return ;
}
void add(int i,int l,int r,int k)
{
    if(tree[i].r<=r && tree[i].l>=l)//�����ǰ���䱻��ȫ������Ŀ�����������������sum+k*(tree[i].r-tree[i].l+1)
    {
        tree[i].sum+=k*(tree[i].r-tree[i].l+1);
        tree[i].lz+=k;//��¼lazytage
        return ;
    }
    push_down(i);//���´���
    if(tree[i*2].r>=l)
        add(i*2,l,r,k);
    if(tree[i*2+1].l<=r)
        add(i*2+1,l,r,k);
    tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
    return ;
}
int search(int i,int l,int r){
    if(tree[i].l>=l && tree[i].r<=r)
        return tree[i].sum;
    if(tree[i].r<l || tree[i].l>r)  return 0;
    push_down(i);
    int s=0;
    if(tree[i*2].r>=l)  s+=search(i*2,l,r);
    if(tree[i*2+1].l<=r)  s+=search(i*2+1,l,r);
    return s;
}
int main()
{
IOS
scan();
build(1,1,n);
while(m--)
{
ll flag;
scanf("%lld",&flag);
if(flag==1)
{
    ll x,y,k;
    scanf("%lld%lld%lld",&x,&y,&k);
    add(1,x,y,k);
}
else if(flag==2)
{
    ll x,y;
    scanf("%lld%lld",&x,&y);
   printf("%lld\n",search(1,x,y));
}
}
    return 0;
}