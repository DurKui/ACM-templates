#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
//�����Ƚ������ò��鼯
//��Ҫ����̰�ģ���ʱ���Ϊ��λʱ�䣬ÿ����λʱ�䣬̰�ĵ�ȡ���������Ĳ�Ʒ��ʼ�������Ӵ�С����
//���ò��鼯ά��ʱ�䣬����ͬ����ʱ��Ĳ�Ʒ����-1����λʱ�����������<=0�������Ʒ��������������£�û��ʱ�����������������Ʒ
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