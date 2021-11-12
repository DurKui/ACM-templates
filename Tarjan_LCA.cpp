/*
 * @Author: Ykui.Chen 
 * @Date: 2021-08-18 16:31:35 
 * @Last Modified by: Ykui.Chen
 * @Last Modified time: 2021-08-18 18:01:02
 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn = 1e6 + 7;
ll f[maxn];
ll head[maxn];
ll vis[maxn];
struct edge {
    ll to, w, next;
} e[maxn];
ll cnt = 0;
ll n, m;
ll z[maxn];
ll dis[maxn];
ll l[2005];
ll r[2005];
void init() {
    cnt = 0;
    memset(vis, 0, sizeof(vis));
    memset(head, -1, sizeof(head));
    memset(dis, 0, sizeof(dis));
    for (ll i = 1; i <= n; i++) {
        f[i] = i;
    }
}
void add(ll u, ll v, ll w)  //链式前向星存图
{
    e[++cnt].next = head[u];
    e[cnt].to = v;
    e[cnt].w = w;
    head[u] = cnt;
}
ll find(ll x) {
    if (x != f[x]) {
        return f[x] = find(f[x]);
    } else
        return f[x];
}


void lca(ll x, ll pre) {
    for (ll i = head[x]; i != -1; i = e[i].next) {
        ll v = e[i].to;
        if (v != pre) {
            lca(v, x);
            if (find(x) != find(v)) {
                f[v] = x;
            }
        }
    }
    vis[x] = 1;
    for(ll i=1;i<=m;i++)
    {
        if(vis[l[i]]&&vis[r[i]])
        {
            if(l[i]==x)
            {
                z[i]=find(r[i]);
            }
            else if(r[i]==x) 
            {
                z[i]=find(l[i]);
            }
            else continue;
        }
    }
}
void dfs(ll x,ll pre)
{
    for (ll i = head[x]; i != -1; i = e[i].next) {
        ll v = e[i].to;
        if (v != pre) {
           dis[v]=dis[x]+e[i].w;
           dfs(v,x);
        }
    }
}
int main() {
    ll t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        init();
        for (ll i = 1; i <= n - 1; i++) {
            ll x, y, z;
            cin >> x >> y >> z;
            add(x, y, z);
            add(y, x, z);
        }
        dfs(1,0);
        for (ll i = 1; i <= m; i++) {
            cin >> l[i] >> r[i];
        }
        lca(1, 0);
        for(ll i=1;i<=m;i++)
        {
            cout<<dis[l[i]]+dis[r[i]]-2*dis[z[i]]<<endl;
        }
    }
    return 0;
}
