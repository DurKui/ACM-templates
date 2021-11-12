#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <list>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const double Pi = acos(-1.0);
const long double eps = 1e-6;
#define mem(a,x) memset(a,x,sizeof a)
#define ll long long
//#define For(i,a,b) for (int i = a; i <= b; ++i)
//#define rush() int T;scanf("%d", &T);for(int Ti=1;Ti<=T;Ti++)
//#define scd(x) scanf("%d", &x)
//#define scl(x) scanf("%lld", &x)
//#define scdd(x,y) scanf("%d %d", &x, &y)
ll solve(int x){
    ll ans=1;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0){
            ll x=1;
            while(x%i==0)
            {
                x++;
                x/=i;
            }
        }
        ans*=x;
    }
    if(x>1) ans*=2;
    return ans;
}
int main(){
    ll n;
    scanf("%lld",&n);
    ll t=solve(n);
    cout<<t;
    return 0;
}
