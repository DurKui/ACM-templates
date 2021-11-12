#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//线段树好题 统计差值
//与线段树模板题的差别在于修改，多了一个参数dis统计总差值
//num=0代表当前区间数字不一样，num不为0代表当前区间数字全为num
//laze记录每次改变的变化量 abs(总的tree[rt].num-k);
//再修改push_down与push_up其他便与模板题无异
using namespace std;
struct node
{
    ll l;
    ll r;
    ll num;//记录当前数值
    ll dis=0;//当前结点总差值
    ll laze=0;//当前结点总改变量
}tree[4000005];
void build(ll rt,ll l,ll r)
{
tree[rt].l=l;
tree[rt].r=r;
if(l==r) {
    tree[rt].num=l;
}
else{
tree[rt].num=0;
ll mid=(l+r)>>1;
build(rt<<1,l,mid);
build(rt<<1|1,mid+1,r);
}
}
void push_down(ll rt)
{
    if(tree[rt].laze)
    {
        tree[rt<<1].dis+=tree[rt].laze*(tree[rt<<1].r-tree[rt<<1].l+1);
        tree[rt<<1|1].dis+=tree[rt].laze*(tree[rt<<1|1].r-tree[rt<<1|1].l+1);
        tree[rt<<1].laze+=tree[rt].laze;
        tree[rt<<1|1].laze+=tree[rt].laze;
        tree[rt<<1].num=tree[rt<<1|1].num=tree[rt].num;
       tree[rt].laze=0;
    }
}
void push_up(ll rt)
{
    tree[rt].dis=tree[rt<<1].dis+tree[rt<<1|1].dis;
    if(tree[rt<<1].num==tree[rt<<1|1].num)
    {
        tree[rt].num=tree[rt<<1].num;
    }
    else tree[rt].num=0;
}
void change(ll rt,ll l,ll r,ll k)
{
if(tree[rt].l>=l&&tree[rt].r<=r&&tree[rt].num)
{
    tree[rt].laze+=abs(tree[rt].num-k);
    tree[rt].dis+=abs(tree[rt].num-k)*(tree[rt].r-tree[rt].l+1);
    tree[rt].num=k;
    return ;
}
push_down(rt);
if(l<=tree[rt<<1].r) change(rt<<1,l,r,k);
if(r>=tree[rt<<1|1].l) change(rt<<1|1,l,r,k);
push_up(rt);
return ;
}
ll query(ll rt,ll l,ll r)
{
    if(tree[rt].l>=l&&tree[rt].r<=r) return tree[rt].dis;
    if(tree[rt].r<l || tree[rt].l>r)  return 0;
    push_down(rt);
    ll ans=0;
   if(l<=tree[rt<<1].r) ans+=query(rt<<1,l,r);
   if(r>=tree[rt<<1|1].l) ans+=query(rt<<1|1,l,r);
   return ans;
}
int main()
{
IOS
ll n,m;
scanf("%lld%lld",&n,&m);
build(1,1,n);
while(m--)
{
    ll flag;
    scanf("%lld",&flag);
    if(flag==1)
    {
        ll l,r,y;
       scanf("%lld%lld%lld",&l,&r,&y);
        change(1,l,r,y);
    }
    else if(flag==2)
    {
        ll x,y;
       scanf("%lld%lld",&x,&y);
        ll ans=query(1,x,y);
        printf("%lld\n",ans);
    }
}
    return 0;
}