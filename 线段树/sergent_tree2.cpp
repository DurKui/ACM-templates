#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//线段树模板2 区间修改，区间查询
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
 void build(int i,int l,int r){//递归建树
    tree[i].l=l;tree[i].r=r;
    if(l==r){//如果这个节点是叶子节点
        tree[i].sum=in[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(i*2,l,mid);//分别构造左子树和右子树
    build(i*2+1,mid+1,r);
    tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;//刚才我们发现的性质return ;
}
void push_down(int i)
{
    if(tree[i].lz!=0)
    {
        tree[i*2].lz+=tree[i].lz;//左右儿子分别加上父亲的lz
        tree[i*2+1].lz+=tree[i].lz;
        int  mid=(tree[i].l+tree[i].r)/2;
        tree[i*2].sum+=tree[i].lz*(mid-tree[i*2].l+1);//左右分别求和加起来
        tree[i*2+1].sum+=tree[i].lz*(tree[i*2+1].r-mid);
        tree[i].lz=0;//父亲lz归零
    }
    return ;
}
void add(int i,int l,int r,int k)
{
    if(tree[i].r<=r && tree[i].l>=l)//如果当前区间被完全覆盖在目标区间里，讲这个区间的sum+k*(tree[i].r-tree[i].l+1)
    {
        tree[i].sum+=k*(tree[i].r-tree[i].l+1);
        tree[i].lz+=k;//记录lazytage
        return ;
    }
    push_down(i);//向下传递
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