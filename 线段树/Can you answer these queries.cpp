#include<cstdio>
#include<math.h>
#include<algorithm>
#define ll long long
const ll maxn=3e5+7;
using namespace std;
//注意x不一定小于y
//注意一个区间全为1则不用更新，1的开方还是1
//hdu4027
struct node
{
    ll l, r;
    ll val;
    ll lz;
}tree[maxn<<1];
ll a[maxn<<1];
void build(ll rt, ll l, ll r)
{
    tree[rt].l=l;
    tree[rt].r=r;
    tree[rt].lz=0;
    if (l==r)
    {
        tree[rt].val=a[l];
        return;
    }
    ll mid=(l+r)>>1;
    build(rt<<1, l, mid);
    build(rt<<1|1, mid+1, r);
    tree[rt].val=tree[rt<<1].val+tree[rt<<1|1].val;
}
/*void push_down(ll rt)
{
    if(tree[rt].lz)
    {
        tree[rt<<1].lz+=tree[rt].lz;
        tree[rt<<1|1].lz+=tree[rt].lz;
        for(ll i=1;i<=tree[rt].lz;i++)
        {
            tree[rt<<1].val=sqrt(tree[rt<<1].val);
            tree[rt<<1|1].val=sqrt(tree[rt<<1|1].val);
        }
        tree[rt].lz=0;
    }
}*/
void change(ll rt, ll l, ll r)
{
    if(tree[rt].val==tree[rt].r-tree[rt].l+1) return ;
    if (tree[rt].l==tree[rt].r&&tree[rt].l>=l&&tree[rt].r<=r)
    {
        tree[rt].val=sqrt(tree[rt].val);
        //tree[rt].lz++;
        return;
    }
   //push_down(rt);
    ll mid=(tree[rt].r+tree[rt].l)>>1;
    if (l<=mid) change(rt<<1, l, r);
    if (r>mid) change(rt<<1|1, l, r);
    tree[rt].val=tree[rt<<1].val+tree[rt<<1|1].val;
}
ll ask(ll rt, ll l, ll r)
{
    if (tree[rt].l>=l&&tree[rt].r<=r)
    {
        return tree[rt].val;
    }
   // push_down(rt);
    ll ans=0;
    ll mid=(tree[rt].r+tree[rt].l)>>1;
    if (l<=mid) ans+=ask(rt<<1, l, r);
    if (r>mid)  ans+=ask(rt<<1|1, l, r);
    return ans;
}
int main()
{
    ll n;
    ll k=1;
    while (scanf("%lld", &n)!=EOF)
    {
        printf("Case #%lld:\n", k++);
        for (ll i=1;i<=n;i++)
        {
            scanf("%lld", &a[i]);
        }
        build(1,1,n);
        ll q;
        scanf("%lld",&q);
        while(q--){
        ll t, x, y;
        scanf("%lld%lld%lld", &t, &x, &y);
        if(x>y) x^=y^=x^=y;
        if (!t) change(1, x, y);
        else {
            printf("%lld\n", ask(1, x, y));
        }
    }
    printf("\n");
    }
    return 0;
}