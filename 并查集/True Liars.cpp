#include <stdio.h>
#include <iostream>
#include <string.h>
#include <map>
#define ll long long
using namespace std;
const int N = 600 + 10;
//���ಢ�鼯+dp
//0Ϊ��ʹ��1Ϊħ��
//���ò��鼯����ά��j
//��Ϊ�޷��б��Ŀ�����ʹ
//�����ȷֳɼ�����Ӫ��ÿһ��Ӫ����ϸ������
//dp��ʼ��dp[0][0]=1��dp[i][j]��ʾi����Ӫ��ÿ����Ӫȡһ�ɱ������ܺ�����Ϊj�ķ���������¼·��
//�������������1�����no
//��֮������˳������������
ll ans[605][2];
ll ant[605][2];
ll dp[605][605];
ll s[605];
ll v[605];
ll path[605][605];
ll find(ll x)
{
  if (s[x] != x)
  {
    ll tmp = s[x];
    s[x] = find(s[x]);
    v[x] += v[tmp];
    v[x] %= 2;
  }
  return s[x];
}
void merge(ll x, ll y, ll c)
{
  ll xx = find(x);
  ll yy = find(y);
  if (xx != yy)
  {
    s[xx] = yy;
    v[xx] = (v[y] - v[x] + c + 2) % 2;
  }
}
int main()
{
  ll m, p1, p2;

  while (~scanf("%lld%lld%lld", &m, &p1, &p2))
  {
    if (m == 0 && p1 == 0 && p2 == 0)
      return 0;
    ll n = p1 + p2;
    for (ll i = 1; i <= n; i++)
    {
      s[i] = i;
      v[i] = 0;
    }
    memset(dp, 0, sizeof(dp));
    memset(ant, 0, sizeof(ant));
    memset(ans, 0, sizeof(ans));
    memset(path, 0, sizeof(path));
    for (ll i = 1; i <= m; i++)
    {
      ll x, y;
      char ss[7];
      scanf("%lld%lld", &x, &y);
      scanf("%s", ss);
      if (ss[0] == 'y')
      {
        merge(x, y, 0);
      }
      else
        merge(x, y, 1);
    }
    map<ll, ll> mp;
    ll cnt = 0;
    for (ll i = 1; i <= n; i++)
    {
      if (find(i) == i)
      {
        mp[i] = ++cnt;
      }
    }
    for (ll i = 1; i <= n; i++)
    {
      ll xx = find(i);
      ans[mp[xx]][v[i]]++;
    }
    dp[0][0] = 1;
    for (ll i = 1; i <= cnt; i++)
    {
      for (ll j = p1; j >= 1; j--)
      {
        if (ans[i][0] <= j && dp[i - 1][j - ans[i][0]])
        {
          dp[i][j] += dp[i - 1][j - ans[i][0]];
          path[i][j] = ans[i][0];
        }
        if (ans[i][1] <= j && dp[i - 1][j - ans[i][1]])
        {
          dp[i][j] += dp[i - 1][j - ans[i][1]];
          path[i][j] = ans[i][1];
        }
      }
    }
    if (dp[cnt][p1] > 1)
    {
      printf("no\n");
    }
    else
    {
      ll k = p1;
      for (ll i = cnt; i >= 1; i--)
      {
        ll op = path[i][k];
        if (op == ans[i][0])
        {
          ant[i][0] = 1;
        }
        else if (op == ans[i][1])
          ant[i][1] = 1;
        k -= op;
      }
      for (ll i = 1; i <= n; i++)
      {
        ll f = find(i);
        if (ant[mp[f]][v[i]])
          printf("%lld\n", i);
      }
      puts("end");
    }
  }
  return 0;
}
