#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define ll long long
const ll maxn=3e5+7;
using namespace std;
//线段树区间染色问题+离散化
struct node
{
    ll l, r, val;
    ll lz;
}tree[maxn<<1];
ll l[maxn], r[maxn], mp[maxn<<1];
ll ans=0;
ll vis[maxn<<1];
ll cnt=0;
void build(ll rt,ll l,ll r)
{
    tree[rt].l=l;
    tree[rt].r=r;
    if(l==r)
    {
        tree[rt].val=0;
        return ;
    }
    ll mid=(l+r)>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    tree[rt].val=0;
}
void push(ll rt)
{
    if(tree[rt].val!=-1)
    {
        tree[rt<<1].val=tree[rt<<1|1].val=tree[rt].val;
      //  tree[rt].val=0;
    }
}
void change(ll rt,ll l ,ll r,ll k)
{
    if(tree[rt].l>=l&&tree[rt].r<=r) 
    {
        tree[rt].val=k;
        return ;
    }
    push(rt);
ll mid=(tree[rt].l+tree[rt].r)>>1;
if(l<=mid) change(rt<<1,l,r,k);
if(r>mid) change(rt<<1|1,l,r,k);

if(tree[rt<<1|1].val==tree[rt<<1].val)
tree[rt].val=tree[rt<<1].val;
else tree[rt].val=-1;
 }
void ask(ll rt,ll l,ll r)
{
if(tree[rt].val==-1)
    {
        ask(rt*2,l,r);
        ask(rt*2|1,l,r);
    }
    else 
    {
        if(vis[tree[rt].val]==0&&tree[rt].val)
        {
            vis[tree[rt].val]=1;
            ans++;
        }
    }
}
int main()
{
    ll t;
    scanf("%lld", &t);
    while (t--)
    {
        ll n;
        scanf("%lld", &n);
        cnt=0;
        for (ll i=0;i<n;i++)
        {
            scanf("%lld%lld", &l[i], &r[i]);
            mp[cnt++]=l[i];
            mp[cnt++]=r[i];
        }
        sort(mp, mp+cnt);
        ll m=unique(mp, mp+cnt)-mp;
        ll k=m;
        for (ll i=1;i<m;i++)
        {
            if (mp[i]-mp[i-1]>1) mp[k++]=mp[i-1]+1;
        }
        sort(mp, mp+k);
        build(1,1,k);
        for(ll i=0;i<n;i++)
        {
            ll x=lower_bound(mp,mp+k,l[i])-mp+1;
            ll y=lower_bound(mp,mp+k,r[i])-mp+1;
            change(1,x,y,i+1);
        }
         ans=0;
         memset(vis,0,sizeof(vis));
        ask(1,1,k);
        printf("%lld\n",ans);
    }
    return 0;
}