#include <stdio.h>
#include <iostream>
#define ll long long
using namespace std;
const double eps = 1e-5;
const ll INF = 0x7fffffff;
const ll MOD = 1e9 + 7;
const ll MAXN = 5e4 + 7;
//��Ȩ���鼯 ʳ����
//��Ϊֻ���������֣����������������ֹ�ϵ���ֱ���a��b��a��b�ԣ�a��bͬһ���֡�Ȼ��ֱ���0����ͬ�࣬1����ǰ��Ժ��棬
//2����ǰ�汻����ԡ��������о�ֻ����������ʱ�������"2 a b"����������ô����a��b�����ǵ���Ҫ��a��b���ӵ�һ�����ϣ�
//������Ҫע�⣬��������˭Ϊ�����أ�������Ҫע�⣬Ϊ�˷�����������������µ�����"a->b"����bΪ���ȣ���ô����a��Ȩֵ��һ��
//�����������ѯ�ʵ�a��b�Ĺ�ϵ������va-vb=1���������ѯ�ʵ�b��a�Ĺ�ϵ�أ���Ȼ��b��a�ԣ���ô���ǲ�ѯʱ�϶�Ҫ�̶���ǰ���
//���氡�������͵õ���-1�����Ϊ�˷������������ÿ�ζ���������3�ٶ�3ȡģ�������ͱ�֤�˵õ�������0,1,2
//�ѵ����ںϲ�������Ӧ����ʲôΪȨֵ
//��ͼ���
ll s[MAXN];
ll sum[MAXN];
ll find(ll x) {
    if (x != s[x]) {
        ll tmp = s[x];
        s[x] = find(s[x]);
        sum[x] = (sum[x] + sum[tmp]) % 3;
    }
    return s[x];
}

int main() {
    ll n, k;
    scanf("%lld%lld", &n, &k);
    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        s[i] = i;
        sum[i] = 0;
    }
    while (k--) {
        ll f, x, y;
        scanf("%lld%lld%lld", &f, &x, &y);
        if (x > n || y > n) {
            ans++;
            continue;
        }
        if (f == 1) {
            if (x == y)
                continue;
            if (find(x) == find(y)) {
                if ((sum[x] - sum[y] + 3) % 3 != 0) {
                    ans++;
                }
            } else {
                ll xx = find(x);
                ll yy = find(y);
                if (xx != yy) {
                    s[xx] = yy;
                    sum[xx] = (sum[y] - sum[x]) % 3;
                }
            }
        } else {
            if (x == y) {
                ans++;
                continue;
            }
            if (find(x) == find(y)) {
                if ((sum[x] - sum[y] + 3) % 3 != 1) {
                    ans++;
                }
            } else {
                ll xx = find(x);
                ll yy = find(y);
                if (xx != yy) {
                    s[xx] = yy;
                    sum[xx] = (sum[y] - sum[x] + 1) % 3;
                }
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}