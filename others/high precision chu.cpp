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
	ll yu=0;
	for(int i=0;i<l;i++)
	s[i+1]=a[i]-'0';
	for(ll i=1;i<=l;i++)
	{ 	
		a1[i]=(s[i]+yu*10)/di;
		yu=(yu*10+s[i])%di;
	}
	ll lb=1;
    while(a1[lb]==0&&lb<l)
    lb++;
	for(ll i=lb;i<=l;i++)
	printf("%lld",a1[i]);
	printf("\n");
	if(yu!=0) 
	printf("yu=%lld\n",yu);
}
int main(){
	gets(a);
	scanf("%lld",&di);
	hpm();
	return 0;
}
