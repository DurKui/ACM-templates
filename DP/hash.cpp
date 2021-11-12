#include<bits/stdc++.h>
#define ll long long
const  ll mod=1e9+7;
using namespace std;
//字符串哈希+暴力
/*若已知一个|S|=n的字符串的hash值，hash[i],1≤i≤n，其子串sl..sr,1≤l≤r≤n，对应的hash值为：
hash=((hash[r]?hash[l?1]?pr?l+1)%mod+mod)%mod*/
ll x[1000005],y[1000005];
ll pos[1000005];
string s,n;
ll qpow(ll x,ll y)
{
    ll ans=1;
    while(y>0)
    {
        if(y&1) 
        {
            ans=(ans*x)%mod;
        }
        x=(x*x)%mod;
        y>>=1;
    }
    return ans;
}
bool check(ll i)
{
    if(x[i-1]!=y[i-1])
    return false;
    ll tmp1=((x[s.length()-1]-x[i]*qpow(131,s.length()-i-1))%mod+mod)%mod;
    ll tmp2=((y[n.length()-1]-x[i-1]*qpow(131,n.length()-i))%mod+mod)%mod;
    if(tmp1!=tmp2) return false;
    return true;
}
int main()
{
cin>>s>>n;
x[0]=s[0];
y[0]=n[0];
ll k=0;
for(ll i=1;i<s.length();i++)
x[i]=(x[i-1]*131+s[i])%mod;
for(ll i=1;i<n.length();i++)
y[i]=(y[i-1]*131+n[i])%mod;
if(((x[s.length()-1]-x[0]*qpow(131,s.length()-1))%mod+mod)%mod==y[n.length()-1])
pos[k++]=1;
for(ll i=1;i<s.length()-1;i++)
{
    if(check(i))
    {
        pos[k++]=i+1;
    }
}
if(x[s.length()-2]==y[n.length()-1]) 
pos[k++]=s.length();
if(k==0) cout<<0<<endl;
else 
{
    cout<<k<<endl;
    for(ll i=0;i<k;i++)
    {
        cout<<pos[i]<<" ";
    }
    cout<<endl;
}
    return  0;
}