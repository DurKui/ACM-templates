#include <stdio.h>
#include<string.h>
#include<iostream>
#define ll long long
using namespace std;
#define mod 998244353
ll dp[105][105];
int main()
{
char s[1005];
while(cin>>s+1)
{
if(strcmp(s+1,"end")==0) return 0;
memset(dp,0,sizeof(dp));
for(ll len=2;len<=strlen(s+1);len++)
{
   for(ll i=1;i<=strlen(s+1)-len+1;i++)
   {
      ll end=i+len-1;
      if(s[i]=='(' &&s[end]==')'||s[i]=='['&&s[end]==']') dp[i][end]=dp[i+1][end-1]+2;
      for(ll k=i;k<end;k++)
      {
         dp[i][end]=max(dp[i][end],dp[i][k]+dp[k+1][end]);
      }
   }
}
cout<<dp[1][strlen(s+1)]<<endl;
}
   return 0;
}