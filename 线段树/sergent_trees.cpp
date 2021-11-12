#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//�߶�������  ����Ⱦɫ���⣬ֻ��¼ĳһ�������Ⱦ����ɫ
//�������߶���ģ����Ĳ�ͬ���ڲ�ѯ���ж�ÿ����ɫ�ж��ٶβ�����������
//����һ�����val��val=-1ʱ����ǰ����û��Ⱦɫ��-2����ǰ����Ⱦɫ�����п����в�ͬ����ɫ�����������Ⱦ����ͬһ����ɫ
//�޸ľ�����ͨ�������޸ģ����ｫlazy tag ��val�ϲ���val����ʾ
//������һ��ans����ͳ��ÿ����ɫ�ж��ٶβ����������䣬�ٽ��䱩���������
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