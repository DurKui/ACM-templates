/*
 * @Author: Ykui.Chen 
 * @Date: 2021-08-18 21:14:02 
 * @Last Modified by: Ykui.Chen
 * @Last Modified time: 2021-08-18 21:43:55

 * 堆排序
 */

#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=1e6+7;
ll a[100];
void adjust(ll x,ll n)
{
    ll pos=x;
    ll k=a[x];
    for(ll i=2*x;i<=n;i*=2)
    {
        if(a[i]<a[i+1]&&i+1<=n) i++;
        if(k<a[i])
        {
            a[pos]=a[i];
            pos=i;
        }
        else break;
    }
    a[pos]=k;
}
void heapsort(ll n)
{
    for(ll i=n/2;i>=1;i--)
    {
        adjust(i,n);
    }
    for(ll i=n;i>=1;i--)
    {
        swap(a[1],a[i]);
        adjust(1,i-1);
    }
}
int main()
{
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++)
    cin>>a[i];
    heapsort(n);
    for(ll i=1;i<=n;i++)
    cout<<a[i]<<" ";
    return 0;
}