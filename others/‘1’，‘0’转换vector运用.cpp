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
	vector<ll>q0;
	vector<ll>q1;
	ll n;
	ll k,m=0;
	string s;
	scanf("%lld%lld",&n,&k);
	getchar();
	cin>>s;
	q1.push_back(-1);
	q0.push_back(-1);
	for(int i=0;i<n;i++){
		if(s[i]=='1') q1.push_back(i);
		else if(s[i]=='0') q0.push_back(i);
	}
	q1.push_back(n-1);
	q0.push_back(n-1);
	if(q0.size()-2<=k) m=n;
	else{
		for(int i=1,j=k;j<q0.size()-1;i++,j++){
			m=max(m,q0[j+1]-q0[i-1]-1);
		}
	}
	if(q1.size()-2<=k) m=n;
	else{
		for(int i=1,j=k;j<q1.size()-1;i++,j++){
			m=max(m,q1[j+1]-q1[i-1]-1);
		}
		
	} 
	
	cout<<m<<endl;
	return 0;
} 
/*���ӣ�https://ac.nowcoder.com/acm/contest/3002/H
��Դ��ţ����

����һ�� \mathit{��01��}��01�������ԣ�ÿ�β������԰� 0 �ַ���Ϊ 1 �ַ������߰� 1 �ַ���Ϊ 0 �ַ�����ν\mathit{��01��}��01��������ֻ���ַ� 0 ���ַ� 1 ���ַ�����
nozomi����� k�β����Ļ��ᡣ�����ڲ���֮���ҳ�һ�������ܳ��������Ӵ�������Ӵ��ϵ������ַ�����ͬ��
nozomi�����ʴ������㣬����Ӵ��ĳ������ֵ�Ƕ��٣�*/
