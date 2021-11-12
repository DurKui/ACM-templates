#include <bits/stdc++.h>
#define ll long long
const int INF=1e6;
using namespace std;
ll dis[1000][1000];
ll n, m;
void floyd()
{
    for (ll k = 1; k <= n; k++)
        for (ll i = 1; i <= n; i++)
        {
            if (dis[i][k] != INF)
                for (ll j = 1; j <= n; j++)
                {
                    if (dis[i][j] > dis[i][k] + dis[k][j])
                    {
                        dis[i][j] = dis[i][k] + dis[k][j];
                    }
                }
        }
        cout<<dis[1][n]<<endl;
}
int main()
{
    while (cin >> n >> m)
    {
        if (!n && !m)
            return 0;
        for (ll i = 1; i <= n; i++)
            for (ll j = 1; j <= n; j++)
                dis[i][j] = INF;
        while (m--)
        {
            ll a, b, c;
            cin >> a >> b >> c;
            dis[a][b] = c;
            dis[b][a] = c;
        }
        floyd();
    }

    return 0;
}