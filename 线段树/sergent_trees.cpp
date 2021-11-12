#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//线段树好题  区间染色问题，只记录某一区间最后染的颜色
//这题与线段树模板题的不同在于查询，判断每个颜色有多少段不连续的区间
//利用一个标记val，val=-1时代表当前区间没有染色，-2代表当前区间染色但是有可能有不同的颜色，其他则代表染上了同一个颜色
//修改就是普通的区间修改，这里将lazy tag 与val合并成val来表示
//再引入一个ans数组统计每种颜色有多少段不连续的区间，再将其暴力输出即可
using namespace std;
struct node
{
    ll l;
    ll r;
    ll val;
}tree[400005];
ll ans[200005];
void build(ll rt,ll l,ll r)
{
tree[rt].l=l;
tree[rt].r=r;
tree[rt].val=-1;
if(l==r) return ;
else{
ll mid=(l+r)>>1;
build(rt<<1,l,mid);
build(rt<<1|1,mid+1,r);
}
}
void push_down(ll rt)
{
if(tree[rt].val!=-2)
{
    tree[rt<<1].val=tree[rt<<1|1].val=tree[rt].val;
}
//tree[rt]=-2;
}
void push_up(ll rt)
{
    if(tree[rt<<1|1].val==tree[rt<<1].val)
    tree[rt].val=tree[rt<<1].val;
    else tree[rt].val=-2;
}
void add(ll rt,ll l,ll r,ll c)
{   
    if(tree[rt].l>=l&&tree[rt].r<=r)
    {
        tree[rt].val=c;
    }
   else{
    push_down(rt);
    ll mid=(tree[rt].r+tree[rt].l)>>1;
    if(l<=mid) add(rt<<1,l,r,c);
    if(r>mid) add(rt<<1|1,l,r,c);
    push_up(rt);
   }
  
}
ll now=-1;
void ask(ll rt)
{
    if(tree[rt].val==-2)
    {
        ask(rt*2);
        ask(rt*2|1);
    }
    else if(tree[rt].val==-1) now=-1;
    else 
    {
        if(now!=tree[rt].val)
        {
            ans[tree[rt].val]++;
            now=tree[rt].val;
        }
    }
}
int main()
{
    IOS
ll n;
while(scanf("%lld",&n)!=EOF)
{
    
    build(1,1,8001);
    while(n--)
    {
        ll l,r,c;
        scanf("%lld%lld%lld",&l,&r,&c);
        add(1,l+1,r,c);
    }
    memset(ans,0,sizeof(ans));
    ask(1);
    for(ll i=0;i<=8000;i++)
    {
        if(ans[i])
        {
            printf("%lld %lld\n",i,ans[i]);
        }
    }
    printf("\n");
    }
    return 0;
}