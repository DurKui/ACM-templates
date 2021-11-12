#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
//这道题比较难利用并查集
//主要运用贪心，把时间分为单位时间，每个单位时间，贪心的取从利润最大的产品开始售卖（从大到小排序）
//利用并查集维护时间，将相同截至时间的产品依次-1个单位时间售卖。如果<=0则这件产品在最优售卖情况下，没有时间卖出，放弃这件产品
ll s[10005];
struct node
{
    ll p,d;
}ss[100005];
bool cmp(node x,node y)
{
    return x.p>y.p;
}
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
ll n;
while(~scanf("%lld",&n))
{
    ll maxx=0;
for(ll i=0;i<n;i++){
scanf("%lld%lld",&ss[i].p,&ss[i].d);
maxx=max(maxx,ss[i].d);
}
for(ll i=1;i<=maxx;i++)
{
s[i]=i;
}
sort(ss,ss+n,cmp);
ll ans=0;
for(ll i=0;i<n;i++)
{
    ll dd=find(ss[i].d);
    if(dd>0)
    {
        s[dd]=dd-1;
        ans+=ss[i].p;
    }
}
printf("%lld\n",ans);
}
return 0;
}