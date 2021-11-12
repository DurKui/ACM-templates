#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//区间修改加上区间查询
//与区间修改与单点查询一样利用差分方程
//a[1]+a[2]+...+a[n]= n * (c[1]+c[2]+...+c[n]) - (0*c[1]+1*c[2]+...+(n-1)*c[n])
//所以要维护两个数状数组，sum1[i]=c[i]，sum2[i]=c[i]*(i-1);
//sum1的更新跟上个问题一样，都是加上x；
//sum2的更新则是加上x*(i-1);(因为第二个数组维护的是c[i]*(i-1)，原来c[i]的地方变成了(c[i]+x),所以原式(c[i]*(i-1),
//变成c[i]*(i-1)+x*(i-1),既增量为x*(i-1))；
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