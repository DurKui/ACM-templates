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
scanf("%lld%lld",&n,&m);
for(ll i=1;i<=n;i++){
scanf("%lld",&s[i]);
}
while(m--)
{
    ll flag;
    scanf("%lld",&flag);
    if(flag==1)
    {
        ll x,y,k;
        scanf("%lld%lld%lld",&x,&y,&k);
        add(x,k);add(y+1,-k);
    }
    else if(flag==2)
    {
        ll x;
        scanf("%lld",&x);
        ll ans=0;
       ans=query(x);
       printf("%lld\n",s[x]+ans);
    }
}

    return 0;
}