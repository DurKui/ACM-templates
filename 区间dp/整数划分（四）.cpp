#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll num[105][105];//dp[i][j]����1��i����j���˺ŵ����ֵ��num[i][j]����i��j�����ִ�С
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
                num[i ][j] = num[ i ][j-1] * 10 + s[j] - '0';//��1��ʼ
                if (i == 1)
                {
                    dp[j][0] = num[1][j];//���ӳ˺ŵ����
                }
            }
        }
        m--;
        dp[2][1] = num[1][1] * num[2][2];//ǰ������˵����
        for (ll i = 1; i <= m; i++)
        {
            for (ll j = 3; j <=n; j++)//�ӵ��������ֿ�ʼȡ
            {
                if (j-1< i)
                    continue;
                for (ll k = 1; k < j; k++)//ö��
                {
                    if (k - 1 < i - 1)
                        continue;
                    dp[j][i] = max(dp[j][i], dp[k][i - 1] * num[k + 1][j]); //״̬ת�Ʒ���
                }
            }
        }
        cout<<dp[n][m]<<endl;
    }
    return 0;
}