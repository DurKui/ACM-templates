#include<bits/stdc++.h>
#define ll long long 
int lowbit(ll x)
{
    return x&(-x);
}
using namespace std;
ll tree[1000005];
ll s[1000005];
ll m,n;
void add(ll i,ll x)
{
while(i<=n)
{
    tree[i]+=x;
    i+=lowbit(i);
}
}
ll query(ll x)
{
    ll ans=0;
    while(x>0)
    {
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}
int main()
{
scanf("%lld",&n);
for(ll i=1;i<=n;i++){
scanf("%lld",&s[i]);
add(i,s[i]);
}
scanf("%lld",&m);
while(m--)
{
    ll flag;
    scanf("%lld",&flag);
    if(flag==0)
    {
        ll x,k;
        scanf("%lld%lld",&x,&k);
        add(x,k);
    }
    else if(flag==1)
    {
        ll x,k;
        scanf("%lld%lld",&x,&k);
        ll ans=0,anss=0;
        ans=query(x-1);
        anss=query(k);
        ll ss=ceil((anss-ans)*1.0/(k-x+1));
        printf("%lld\n",ss);
    }
}

    return 0;
}