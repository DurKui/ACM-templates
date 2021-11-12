#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#define ll long long 
using namespace std;
ll s[100005];
ll vis[100005];
//利用并查集的特点，判断结点间的连通性
//抓准树的特点
//注意:
//1、空树是树
//2、当一个结点指向自己，则不是树
//3、只有一个根节点
//4、没有回路
ll find(ll x)
{
    if(x!=s[x])
    {
        s[x]=find(s[x]);
    }
    return s[x];
}
int main()
{
ll a,b;
ll k=1;
while(~scanf("%lld%lld",&a,&b))
{
    if(a==-1||b==-1)
    break;
    if(a==0||b==0)
    {
        printf("Case %lld is a tree.\n",k++);
        continue;
    }
    for(ll i=0;i<=100005;i++){
    s[i]=i;
    vis[i]=0;
    }
    ll flag=0;
    s[a]=b;
    vis[a]=1;
    vis[b]=1;
    ll minn=min(a,b);
    ll maxx=max(a,b);
    while(~scanf("%lld%lld",&a,&b))
    {
        if(a==0||b==0)
        break;
        minn=min(min(a,b),minn);
        maxx=max(max(a,b),maxx);
        vis[a]=1;
        vis[b]=1;
        ll x=find(a);
        ll y=find(b);
        if(x==y)
        flag=1;
        else 
        {
            s[x]=y;
        }
    }
    if(flag) printf("Case %lld is not a tree.\n",k++);
    else 
    {
ll ans=0;
ll anss=0;
for(ll i=minn;i<=maxx;i++)
{
if(vis[i]&&s[i]==i)
ans++;
if(vis[i]) anss++;
}
if(anss==1&&ans==1) printf("Case %lld is not a tree.\n",k++);
else if(ans==1) printf("Case %lld is a tree.\n",k++);
else if(ans>1) printf("Case %lld is not a tree.\n",k++);
    }
}
    return 0;
}