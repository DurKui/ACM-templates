#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <map>
#define ll long long
using namespace std;
ll s[500005];
ll sum[500005];
ll k = 0;
ll find(ll x)
{
    if (x != s[x])
    {
        ll t = s[x];
        s[x] = find(s[x]);
        sum[x] = sum[x] ^ sum[t];
    }
    return s[x];
}
map<ll, ll> mp;
int main()
{
    ll n;
    ll t;
    scanf("%lld", &n);
    for (ll i = 0; i <= n; i++)
    {
        s[i] = i;
        sum[i] = 0;
    }
    scanf("%lld", &t);
    ll ans = 0;
    while (t--)
    {
        ll a, b;
        scanf("%lld%lld", &a, &b);
        a--;
        if (mp.find(a) == mp.end())
            mp[a] = k++;
        if (mp.find(b) == mp.end())
            mp[b] = k++;
        char ss[10005];
        ll tmp;
        scanf("%s", ss);
        if (ss[0] == 'e')
            tmp = 0;
        else
            tmp = 1;
        ll xx = find(mp[a]);
        ll yy = find(mp[b]);
        if (xx == yy)
        {
            if ((sum[a] ^ sum[b]) == tmp)
                ans++;
            else
                break;
        }
        else
        {
            s[xx] = yy;
            sum[xx] = (sum[a] ^ sum[b] ^ tmp);
            ans++;
        }
    }
    printf("%lld\n", ans);
    return 0;
}