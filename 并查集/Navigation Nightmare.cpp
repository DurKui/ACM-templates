#include <stdio.h>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const double eps = 1e-5;
const ll INF = 0x7fffffff;
const ll MOD = 1e9 + 7;
const ll MAXN = 5e4 + 7;
//��Ȩ���鼯
//����x��������y�����ϵ�����Ȩֵ
//���ݶ����ϱ��ж���x������y����������ֵ���Ǹ�ֵ
//��ѯ�ʵ����������index��С���������������ò��鼯ά��x��������y�����ϵ�Ȩֵ
//merge������ϸ��Ҫע��
//���о��Ǽ�¼�𰸵�ʱ��Ҫ��¼��ʼ�±�
//����±�������򣬾Ϳ��԰��ճ�ʼ˳�������
struct node
{
    ll u, v, len;
    char s;
} node[100005];
struct q
{
    ll u, v, pos, index;

} w[10005];
bool cmp2(q x, q y)
{
    return x.index < y.index;
}
struct gather
{
    ll x, y, s;
} g[100005];
struct anss
{
    ll ans, pos;
} an[100005];
bool cmp(anss a, anss b)
{
    return a.pos < b.pos;
}
ll n, m;
ll find(ll x)
{
    if (x != g[x].s)
    {
        ll t = g[x].s;
        g[x].s = find(g[x].s);
        g[x].x += g[t].x;
        g[x].y += g[t].y;
    }
    return g[x].s;
}
void merge(struct node x)
{
    ll xx = find(x.u);
    ll yy = find(x.v);
    if (xx != yy)
    {
        g[xx].s = yy;
        if (x.s == 'N')
        {
            g[xx].y = g[x.v].y + x.len - g[x.u].y;
            g[xx].x = g[x.v].x - g[x.u].x;
        }
        else if (x.s == 'S')
        {

            g[xx].y = g[x.v].y - x.len - g[x.u].y;
            g[xx].x = g[x.v].x - g[x.u].x;
        }
        else if (x.s == 'E')
        {

            g[xx].x = g[x.v].x + x.len - g[x.u].x;
            g[xx].y = g[x.v].y - g[x.u].y;
        }
        else
        {

            g[xx].x = g[x.v].x - x.len - g[x.u].x;
            g[xx].y = g[x.v].y - g[x.u].y;
        }
    }
}
int main()
{
    scanf("%lld%lld", &n, &m);
    for (ll i = 1; i <= n; i++)
    {
        g[i].s = i;
        g[i].x = g[i].y = 0;
    }
    for (ll i = 0; i < m; i++)
        scanf("%lld%lld%lld%s", &node[i].u, &node[i].v, &node[i].len, &node[i].s);
    ll k;
    scanf("%lld", &k);
    for (ll i = 0; i < k; i++)
    {
        scanf("%lld%lld%lld", &w[i].u, &w[i].v, &w[i].index);
        w[i].pos = i;
    }
    sort(w, w + k, cmp2);
    ll ans, j = 0;
    for (ll i = 0; i < k; i++)
    {
        while (j < w[i].index)
        {
            merge(node[j]);
            j++;
        }
        ll x = find(w[i].u);
        ll y = find(w[i].v);
        if (x != y)
        {
            ans = -1;
        }

        else
            ans = abs(g[w[i].u].x - g[w[i].v].x) + abs(g[w[i].u].y - g[w[i].v].y);
        an[i].ans = ans;
        an[i].pos = w[i].pos;
    }
    sort(an, an + k, cmp);
    for (ll i = 0; i < k; i++)
        printf("%lld\n", an[i].ans);
    return 0;
}