#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <map>
#define N 10010
#define HASH 10000
#define ll long long
using namespace std;
//反向并查集
//先忽略被摧毁的通道，用并查集维护剩下的通道，将merge操作调整为父节点的能量最大
//再反向询问与当前星球相通的能量最大的星球，如果小于等于当前星球的能量，则为-1否则为此星球
//当反向维护到destroy时再将此通道加入
ll s[100005];
ll sum[100005];
char ss[100005][10];
ll a[100005];
ll b[100010];
ll c[100010];
ll d[100010];
ll ans[100005];
map<ll, ll> mp;
ll find(ll x)
{
    if (x != s[x])
    {
        s[x] = find(s[x]);
    }
    return s[x];
}
void merge(ll a, ll b)
{
    ll x = find(a);
    ll y = find(b);
    if (x != y)
    {
        if (sum[x] > sum[y])
        {
            s[y] = x;
        }
        else if (sum[x] < sum[y])
            s[x] = y;
        else
        {
            if (x < y)
                s[y] = x;
            else if (y < x)
                s[x] = y;
        }
    }
}
int main()
{
    ll flag = 0;
    ll n;
    while (~scanf("%lld", &n))
    {
        if (flag)
            printf("\n");
        flag = 1;
        for (ll i = 0; i < n; i++)
            scanf("%lld", &sum[i]);
        ll m;
        scanf("%lld", &m);
        for (ll i = 0; i < m; i++)
        {
            scanf("%lld%lld", &a[i], &b[i]);
            if (a[i] > b[i])
                swap(a[i], b[i]);
        }
        ll q;
        scanf("%lld", &q);
        mp.clear();
        for (ll i = 0; i < q; i++)
        {
            scanf("%s", ss[i]);
            if (ss[i][0] == 'd')
            {
                scanf("%lld%lld", &c[i], &d[i]);
                if (c[i] > d[i])
                    swap(c[i], d[i]);
                mp[c[i] * HASH + d[i]] = 1;
            }
            else
                scanf("%lld", &c[i]);
        }
        for (ll i = 0; i <= n; i++)
        {
            s[i] = i;
        }
        for (ll i = 0; i < m; i++)
        {
            if (mp[a[i] * HASH + b[i]] == 1)
                continue;
            merge(a[i], b[i]);
        }
        ll k = 0;
        for (ll i = q - 1; i >= 0; i--)
        {
            if (ss[i][0] == 'q')
            {
                ll e = find(c[i]);
                if (sum[e] > sum[c[i]])
                    ans[k++] = e;
                else
                    ans[k++] = -1;
            }
            else
                merge(c[i], d[i]);
        }
        for (ll i = k - 1; i >= 0; i--)
            printf("%lld\n", ans[i]);
    }
    return 0;
}