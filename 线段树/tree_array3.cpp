#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//�����޸ļ��������ѯ
//�������޸��뵥���ѯһ�����ò�ַ���
//a[1]+a[2]+...+a[n]= n * (c[1]+c[2]+...+c[n]) - (0*c[1]+1*c[2]+...+(n-1)*c[n])
//����Ҫά��������״���飬sum1[i]=c[i]��sum2[i]=c[i]*(i-1);
//sum1�ĸ��¸��ϸ�����һ�������Ǽ���x��
//sum2�ĸ������Ǽ���x*(i-1);(��Ϊ�ڶ�������ά������c[i]*(i-1)��ԭ��c[i]�ĵط������(c[i]+x),����ԭʽ(c[i]*(i-1),
//���c[i]*(i-1)+x*(i-1),������Ϊx*(i-1))��
int lowbit(ll x)
{
    return x&(-x);
}
ll tree1[1000005];
ll tree2[10000005];
ll a[1000005];
ll n;
void add(ll x,ll k)
{
    ll i=x;
    while(x<=n)
    {
        tree1[x]+=k;
        tree2[x]+=k*(i-1);
        x+=lowbit(x);
    }
}
void big_add(ll x,ll y,ll k)
{
    add(x,k);
    add(y+1,-k);
}
ll ask(ll x)
{
    ll ans1=0,ans2=0;
    ll nn=x;
    while(x>0)
    {
        ans1+=nn*tree1[x];
        ans2+=tree2[x];
        x-=lowbit(x);
    }
    return ans1-ans2;
}
ll query(ll x,ll y)
{
    return ask(y)-ask(x-1);
}
int main()
{
 IOS
ll m;
scanf("%lld%lld",&n,&m);
for(ll i=1;i<=n;i++)
scanf("%lld",&a[i]);
for(ll i=1;i<=n;i++)
{
    add(i,a[i]-a[i-1]);
}
while(m--){
ll flag;
scanf("%lld",&flag);
if(flag==1)
{
    ll x,y,k;
   scanf("%lld%lld%lld",&x,&y,&k);
    big_add(x,y,k);
}
else 
{
    ll x,y;
   scanf("%lld%lld",&x,&y);
   printf("%lld\n",query(x,y));
}
}
    return 0;
}