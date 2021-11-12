#include <bits/stdc++.h>
using namespace std;
//从左边界开始往右的最大连续长度 rl，从右边界开始往左的最大连续长度 ll，和无条件的最大连续长度 ml
//左边界指[l,r]的l，右边界指[l,r]的r
//hdu1540
struct node
{
	int ll,rl,ml;
}tree[50005*4];
int n,m,x;
char c;
stack<int> sk;
void build(int l,int r,int rt)
{
	tree[rt].ll=tree[rt].rl=tree[rt].ml=r-l+1;
	if(l==r) return;
	build(l,(l+r)/2,rt<<1);
	build((l+r)/2+1,r,rt<<1|1);
}
void update(int x,int c,int l,int r,int rt)
{
	if(x<l||x>r) return;
	if(l==r) 
	{
		tree[rt].ll=tree[rt].rl=tree[rt].ml=c;
		return;
	}
	update(x,c,l,(l+r)/2,rt<<1);
	update(x,c,(l+r)/2+1,r,rt<<1|1);
	//最大连续长度是 1.左儿子最大长 2.右儿子最大长 3.左儿子右边界+右儿子左边界最大长 之一 
	tree[rt].ml=max(max(tree[rt<<1].ml,tree[rt<<1|1].ml),tree[rt<<1].rl+tree[rt<<1|1].ll);
	tree[rt].ll=tree[rt<<1].ll;//最大左长为左儿子左长，若左儿子左长满区间，则要加右儿子左长 
	if(tree[rt].ll==(l+r)/2-l+1) tree[rt].ll+=tree[rt<<1|1].ll;
	tree[rt].rl=tree[rt<<1|1].rl;//最大右长同理 
	if(tree[rt].rl==r-(l+r)/2) tree[rt].rl+=tree[rt<<1].rl;
}
int query(int x,int l,int r,int rt)
{
	//叶子结点 或 完全连续 或 完全不连续 直接返回 
	if(l==r||tree[rt].ml==r-l+1||!tree[rt].ml) return tree[rt].ml;
	if(x<(l+r)/2+1-tree[rt<<1].rl) return query(x,l,(l+r)/2,rt<<1);//在中间地带左侧 
	if(x>(l+r)/2+tree[rt<<1|1].ll) return query(x,(l+r)/2+1,r,rt<<1|1);//在中间地带右侧 
	return tree[rt<<1].rl+tree[rt<<1|1].ll;//在中间地带直接返回加合 
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		build(1,n,1);
		while(m--)
		{
			getchar();
			scanf("%c",&c);
			if(c=='D') scanf("%d",&x),update(x,0,1,n,1),sk.push(x);
			else if(c=='R') update(sk.top(),1,1,n,1),sk.pop();
			else scanf("%d",&x),printf("%d\n",query(x,1,n,1));
		}
	}
	return 0;
}