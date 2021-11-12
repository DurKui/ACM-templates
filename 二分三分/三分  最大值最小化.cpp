#pragma warning (disable :4996)
#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const double eps = 1e-7;
const int N = 1e5 + 10;
 
int n;
struct Point {
    int x, y;
}a[N];
double Maxn(double x) {
    double maxn = 0;
    for (int i = 1; i <= n; i++) {
        double tmp = sqrt(a[i].y * a[i].y + (a[i].x - x) * (a[i].x - x));
        if (maxn < tmp) maxn = tmp;
    }
    return maxn;
}
double lmid,rmid;
void solve() {
    double le = -10000, r = 10000;
    while (le + eps < r) {
         lmid = le + (r - le)/2.0;
		 rmid = lmid+(r-lmid)/2.0;
        if (Maxn(rmid) < Maxn(lmid))
            le = lmid;
        else
            r = rmid;
    }
    printf("%.4lf\n", Maxn(le));
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i].x, &a[i].y);
    }
    solve();
 
}
