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
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	char s[200005] ;
	int v[200005];
	int p[200005];
	scanf("%s",s+1);
	queue<int>q;
	v[0]=0;
	int maxx=0;
	for(int i=1;i<=n;i++){
	if(s[i]=='1')
	{
		v[i]=v[i-1]+1;
		}else{
			if(q.size()<k)
			{
				v[i]=v[i-1]+1;
				q.push(i);
			}
			else if(q.size()>=k)
			{
				v[i]=i-q.front();
				q.pop();
				q.push(i);
			}
		}	
		if(v[i]>maxx)
		maxx=v[i];
	}
	cout<<maxx<<endl;
	return 0;
}
