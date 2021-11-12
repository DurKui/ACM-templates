#include <stdio.h>
#include <algorithm>
#include <string.h>
#include<iostream>
#include<set>
typedef long long ll;
using namespace std;
//const int maxn = 1e5+10;
ll add[400005];
ll tree[400005];
void push_down(ll rt, ll num)
{
	if(add[rt]){
		add[rt<<1]=add[rt];
		add[rt<<1|1]=add[rt];
		tree[rt<<1]=(num-(num>>1))*add[rt];
		tree[rt<<1|1]=(num>>1)*add[rt];
		add[rt]=0; 
	}
}
void build_tree(ll l,ll r,ll rt){
	add[rt]=0;
	if(l==r){
		tree[rt]=1;
		return ;
	}
	ll mid=(l+r)>>1;
	build_tree(l,mid,rt<<1);
	build_tree(mid+1,r,rt<<1|1);
	tree[rt]=tree[rt<<1]+tree[rt<<1|1];
}
void update(ll a,ll b,ll c,ll l,ll r,ll rt)
{
	if(a<=l&&b>=r){
		tree[rt]=(r-l+1)*c;
		add[rt]=c;
		return;
	}
	push_down(rt,r-l+1);
	ll mid=(r+l)>>1;
	if(a<=mid) update(a,b,c,l,mid,rt<<1);
	if(b>mid) update(a,b,c,mid+1,r,rt<<1|1);
	tree[rt]=tree[rt<<1]+tree[rt<<1|1];
}
	
int main(){
	ll n;
	ll t;
	scanf("%lld",&t);
	ll k=1;
while(t--)
{	
memset(tree,0,sizeof(tree));
memset(add,0,sizeof(add));
	ll q;
scanf("%lld",&n);
scanf("%lld",&q);
	build_tree(1,n,1);
//	cout<<tree[1]<<endl;
	while(q--){
	ll x,y,z;
	scanf("%lld%lld%lld",&x,&y,&z);
	update(x,y,z,1,n,1);
//	cout<<tree[1]<<endl;	
}
	printf("Case %lld: The total value of the hook is %lld.\n",k++,tree[1]);
	}
	return 0;
}
