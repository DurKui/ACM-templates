#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#define ll long long 
using namespace std;
ll s[100005];
ll vis[100005];
//���ò��鼯���ص㣬�жϽ������ͨ��
//ץ׼�����ص�
//ע��:
//1����������
//2����һ�����ָ���Լ���������
//3��ֻ��һ�����ڵ�
//4��û�л�·
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