/*
 * @Author: Ykui.Chen 
 * @Date: 2021-08-18 21:14:39 
 * @Last Modified by: Ykui.Chen
 * @Last Modified time: 2021-08-18 21:44:37
 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn = 1e6 + 7;
ll a[100];
    ll temp[100];
void merge(ll l,ll mid,ll r)
{
    ll i=l;
    ll j=mid+1;
    ll k=0;
    while(i<=mid&&j<=r)
    {
        if(a[i]<=a[j])
        {
            temp[k++]=a[i++];
        }
        else temp[k++]=a[j++];
    }
    while(i<=mid)
    {
        temp[k++]=a[i++];
    }
    while(j<=r) temp[k++]=a[j++];
    for(ll i=l;i<=r;i++)
    {
        a[i]=temp[i-l];
    }
}
void merge_sort(ll l,ll r)
{
    if(l<r)
    {
        ll mid=(l+r)>>1;
        merge_sort(l,mid);
        merge_sort(mid+1,r);
        merge(l,mid,r);
    }
}
int main()
{
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++)
    cin>>a[i];
    merge_sort(1,n);
    for(ll i=1;i<=n;i++)
    cout<<a[i]<<" ";
    return 0;
}