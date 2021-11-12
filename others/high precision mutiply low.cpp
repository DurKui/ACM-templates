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
char a[5000];
ll s[5005],a1[5000],di;
void hpm(){
	memset(s,0,sizeof(s));
	memset(a1,0,sizeof(a1));
	ll l=strlen(a);
	for(int i=0;i<l;i++)
	a1[l-i-1]=a[i]-'0';
	ll jinwei=0;
	for(ll i=0;i<l;i++)
	{ 	
		s[i]=a1[i]*di+jinwei;
		jinwei=s[i]/10;
		s[i]%=10;
	}
	if(jinwei>0) {
	s[l]=jinwei;
	l++;
    while(s[l-1]>=10){
        s[l]=s[l-1]/10;
        s[l-1]=s[l-1]%10;
        l++;
    }
            }
    while(s[l-1]==0&&l>1)
    l--;
	for(ll i=l-1;i>=0;i--)
	printf("%lld",s[i]);
}
int main(){
	gets(a);
	scanf("%lld",&di);
	hpm();
	return 0;
}
