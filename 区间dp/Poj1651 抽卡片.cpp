#include <stdio.h>
#include<string.h>
#include<iostream>
#define ll long long
using namespace std;
#define INF 1e10
ll dp[105][105];
int main()
{
ll n;
cin>>n;
ll a[105];
for(ll i=1;i<=n;i++)
{
   cin>>a[i];
}
for(ll len=2;len<=n;len++)
{
   for(ll i=1;i<=n-len;i++)
   {
      ll end=i+len;
      dp[i][end]=10000000;
      for(ll k=i;k<=end;k++)
      {
         dp[i][end]=min(a[k]*a[i]*a[end]+dp[i][k]+dp[k][end],dp[i][end]);
      }
   }
}
cout<<dp[1][n]<<endl;
   return 0;
}