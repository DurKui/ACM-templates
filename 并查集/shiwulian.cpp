#include <stdio.h>
#include <iostream>
#define ll long long
using namespace std;
const double eps = 1e-5;
const ll INF = 0x7fffffff;
const ll MOD = 1e9 + 7;
const ll MAXN = 5e4 + 7;
//带权并查集 食物链
//因为只有三个物种，这里我们设置三种关系，分别是a吃b，a被b吃，a和b同一物种。然后分别用0代表同类，1代表前面吃后面，
//2代表前面被后面吃。我们先研究只有两个物种时假设给出"2 a b"的条件，那么代表a吃b，考虑到需要把a，b连接到一个集合，
//但是需要注意，我们设置谁为祖先呢？这里需要注意，为了方便起见我们设置如下的向量"a->b"，即b为祖先，那么更新a的权值加一。
//接着下面如果询问到a和b的关系，就是va-vb=1。但是如果询问到b和a的关系呢，显然是b被a吃，那么我们查询时肯定要固定的前面减
//后面啊，这样就得到了-1，因此为了方便起见，我们每次二者相减后加3再对3取模，这样就保证了得到的数是0,1,2
//难点在于合并操作，应该设什么为权值
//画图理解
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