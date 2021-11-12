#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll num[105][105];//dp[i][j]代表1到i加上j个乘号的最大值；num[i][j]代表i到j的数字大小
ll dp[105][105];
int main()
{
    ll t;
    cin>>t;
    while (t--)
    {
        char s[105];
        ll m;
        cin >> s+1 >> m;
        cin.get();
        ll n=strlen(s+1);
        memset(dp, 0, sizeof(dp));
        memset(num, 0, sizeof(num));
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = i; j <= n; j++)
            {
                num[i ][j] = num[ i ][j-1] * 10 + s[j] - '0';//从1开始
                if (i == 1)
                {
                    dp[j][0] = num[1][j];//不加乘号的情况
                }
            }
        }
        m--;
        dp[2][1] = num[1][1] * num[2][2];//前两个相乘的情况
        for (ll i = 1; i <= m; i++)
        {
            for (ll j = 3; j <=n; j++)//从第三个数字开始取
            {
                if (j-1< i)
                    continue;
                for (ll k = 1; k < j; k++)//枚举
                {
                    if (k - 1 < i - 1)
                        continue;
                    dp[j][i] = max(dp[j][i], dp[k][i - 1] * num[k + 1][j]); //状态转移方程
                }
            }
        }
        cout<<dp[n][m]<<endl;
    }
    return 0;
}