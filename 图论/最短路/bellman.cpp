#include<bits/stdc++.h>
#define ll long long 
using namespace std;
//Bellman_ford 算法,数组存边
//符合并行计算的思想
struct edge{
    ll u,v,w;
}e[10005];
ll n,m,cnt;
ll pre[10005];
void bellman()
{
    ll s=1;
    ll d[100005];
    for(ll i=0;i<=n;i++) d[i]=10005;
    d[s]=0;
    for(ll k=1;k<=n;k++)//n轮操作
    {
        for(ll i=0;i<cnt;i++)//询问每条边
        {
            ll x=e[i].u; ll y=e[i].v;
            if(d[x]>d[y]+e[i].w)
            {
                d[x]=d[y]+e[i].w;
            }
        }
    }
}
int main()
{
while(cin>>n>>m)
{
    if(!n&&!m) return 0;
    cnt=0;
    while(m--)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        e[cnt].u=u;
        e[cnt].v=v;
        e[cnt].w=w;
        cnt++;
        e[cnt].u=v;
        e[cnt].v=u;
        e[cnt].w=w;
        cnt++;
    }
    bellman();
}
    return 0;
}