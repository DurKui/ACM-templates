/*
 * @Author: Ykui.Chen 
 * @Date: 2021-08-18 21:14:39 
 * @Last Modified by: Ykui.Chen
 * @Last Modified time: 2021-08-18 21:37:34
 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn = 1e6 + 7;
ll a[100];
ll partition(ll l, ll r) {
    ll L = l;
    ll R = r;
    ll temp = a[l];
    while (L < R) {
        while (a[R] >= temp&&L<R) {
            R--;
        }
        a[L]=a[R];
        while (a[L] <= temp&&L<R) {
            L++;
        }
       a[R]=a[L];
    }
    a[L]=temp;
    return L;
}
void quick_sort(ll l, ll r) {
    if (l < r) {
        ll k = partition(l, r);
        quick_sort(l, k - 1);
        quick_sort(k+1, r);
    }
}
int main() {
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    quick_sort(1,n);
    for (ll i = 1; i <= n; i++)
        cout << a[i] << " ";
    return 0;
}