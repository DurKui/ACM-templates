#include <bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
struct MA{
  int s[3][3];
  MA(){
    memset(s,0,sizeof(s));
  }
};
MA Multi(MA x,MA y)
{ 
  MA res;
  for(ll i=0;i<2;i++)
  {
    for(ll j=0;j<1;j++)
    {
      for(ll k=0;k<2;k++)
      {
        res.s[i][j]=(res.s[i][j]+x.s[i][k]*y.s[k][j])%mod;
      }
    }
  }
return res;
}
MA fastm(MA s,int n)
{
  MA res;
  res.s[0][0]=1;
  res.s[1][0]=1;
  while(n)
  {
    if(n&1)
    {
      res=Multi(s,res);
    }
    s=Multi(s,s);
    n>>=1;
  }
  return res;
}
int main()
{
  MA k;
ll a,b,n;
scanf("%lld%lld%lld",&a,&b,&n);
k.s[0][0]=a;
k.s[0][1]=b;
k.s[1][0]=1;
k.s[1][1]=0;
MA kk;
kk=fastm(k,n-1);
printf("%lld\n",kk.s[0][0]);
  return 0;
}