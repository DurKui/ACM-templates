/*
 * @Author: Ykui.Chen 
 * @Date: 2021-08-18 21:14:39 
 * @Last Modified by: Ykui.Chen
 * @Last Modified time: 2021-08-18 21:44:37
 * 主席树（可持久化权值线段树） poj2104
 * 单点修改，区间查询第k大值
 */
#include <iostream>
#include<stdio.h>
#include<algorithm>
#define ll long long
using namespace std;
const ll maxn = 1e5 + 7;
struct segmentTree {
    ll l, r;//左右儿子
    ll maxx;

} tree[maxn * 40];
ll tot = 0;
ll root[maxn];
ll n, m, a[maxn];
ll b[maxn];
ll build(ll l, ll r) {//建立一颗空树
    ll p = (++tot);
    if (l == r) {
        tree[p].maxx = 0;
        return p;
    }
    ll mid = (l + r) >> 1;
    tree[p].l = build(l, mid);
    tree[p].r = build(mid + 1, r);
    tree[p].maxx = tree[tree[p].l].maxx + tree[tree[p].r].maxx;
    return p;
}
ll insert(ll rt, ll l, ll r, ll x, ll val) {//插入操作，新建一条链
    ll p = (++tot);
    tree[p] = tree[rt];
    if (l == r) {
        tree[p].maxx = val;
        return p;
    }
   //cout<<tree[tree[p].l].maxx<<" "<<tree[tree[p].r].maxx<<endl;
    ll mid = (l + r) >> 1;
    if (x <= mid) {
        tree[p].l = insert(tree[rt].l, l, mid, x, val);
    } else {
        tree[p].r = insert(tree[rt].r, mid + 1, r, x, val);
    }
    tree[p].maxx = tree[tree[p].l].maxx + tree[tree[p].r].maxx;
    return p;
}
ll ask(ll lc,ll rc, ll l, ll r, ll k) {//查询操作
   if(l==r)
   {
       return l;
   }
   ll mid=(l+r)>>1;
  // cout<<tree[tree[rc].l].maxx<<" "<<tree[tree[lc].l].maxx<<endl;
   if(tree[tree[rc].l].maxx-tree[tree[lc].l].maxx>=k)
   {
       return ask(tree[lc].l,tree[rc].l,l,mid,k);
   }
   else return ask(tree[lc].r,tree[rc].r,mid+1,r,k-(tree[tree[rc].l].maxx-tree[tree[lc].l].maxx));

}
int main() {
    scanf("%lld%lld",&n,&m);
    root[0] = build(1, n);
    for(ll i=1;i<=n;i++)
    {
       scanf("%lld",&a[i]);
        b[i-1]=a[i];
    }
    sort(b,b+n);
    ll N=unique(b,b+n)-b;
    for (ll i = 1; i <= n; i++) {
        ll x=lower_bound(b,b+N,a[i])-b;
        root[i] = insert(root[i-1], 1, n, x+1, 1);
       // cout<<tree[root[i]].maxx<<endl;
    }
  //  cout<<tree[tree[14].l].maxx<<" "<<tree[30].maxx<<endl;
    while(m--)
    {
        ll l,r,k;
       scanf("%lld%lld%lld",&l,&r,&k);
        ll ans=ask(root[l-1],root[r],1,n,k);
        printf("%lld\n",b[ans-1]);
    }
    return 0;
}
