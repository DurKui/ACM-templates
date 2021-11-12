#include <stdio.h>
#include <iostream>
#define ll long long
using namespace std;
const double eps = 1e-5;
const ll INF = 0x7fffffff;
const ll MOD = 1e9 + 7;
const ll MAXN = 5e4 + 7;
//带权并查集维护种类并查集
//0与1分别代表不同种类
//注意维护并查集加以判断即可   注意输入形式
ll s[1000005];
ll sum[1000005];
ll find(ll x)
{
    if (x != s[x])
    {
        ll tmp = s[x];
        s[x] = find(s[x]);
        sum[x] = sum[x]^sum[tmp];
    }
    return s[x];
}
int main()
{
    ll t;
    bool flag = false;
    scanf("%lld", &t);
    ll k = 1;
    while (t--)
    {
        ll n, m;
        scanf("%lld%lld", &n, &m);
        for (ll i = 0; i <= n; i++)
        {
            s[i] = i;
            sum[i] = 0;
        }
        flag = false;
        while (m--)
        {
            ll a, b;
            scanf("%lld%lld", &a, &b);
            ll xx = find(a);
            ll yy = find(b);
            if (xx == yy)
            {
                if (sum[a] ^ sum[b]==0)
                {
                    flag = true;
                    continue;
                }
            }
            else
            {
                s[xx] = yy;
                sum[xx] = (sum[a] ^ sum[b] ^ 1) & 1;
            }
        }
        printf("Scenario #%lld:\n", k++);
        if (flag)
            printf("Suspicious bugs found!\n");
        else
            printf("No suspicious bugs found!\n");
        printf("\n");
    }
    return 0;
}