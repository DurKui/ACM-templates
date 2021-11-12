#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//线段树模板1 点修改，区间查询
struct Tree{
    ll l,r;
    ll sum=0;
}tree[40005];
ll in[40005];
void build(ll l,ll r,ll rt)
{
    tree[rt].l=l;
    tree[rt].r=r;
    if(l==r)
    {
        tree[rt].sum=in[rt];
    }
    ll mid=(l+r)>>1;
    build(l,mid,rt*2);
    build(mid+1,r,rt*2|1);
    tree[rt].sum=tree[rt*2].sum+tree[rt*2|1].sum;
}
void add(ll rt,ll dis,ll k)
{
    if(tree[rt].l==tree[rt].r)
    tree[rt].sum+=k;
    if(dis<=tree[rt*2].r) add(rt*2,dis,k);
    if(dis>=tree[rt*2|1].l) add(rt*2|1,dis,k);
    tree[rt].sum=tree[rt*2|1].sum+tree[rt*2].sum;
}
ll search(ll l,ll r,ll rt)
{
    if(tree[rt].l>=l&&tree[rt].r<=r)
    {
        return tree[rt].sum;
    }
    ll ans=0;
    if(r>=tree[rt*2|1].l) ans+=search(l,r,rt*2|1);
    if(l<tree[rt*2].r) ans+=search(l,r,rt*2);
    return ans;
}
int main()
{
    return 0;
}