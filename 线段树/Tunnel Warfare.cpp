#include <bits/stdc++.h>
using namespace std;
//����߽翪ʼ���ҵ������������ rl�����ұ߽翪ʼ���������������� ll����������������������� ml
//��߽�ָ[l,r]��l���ұ߽�ָ[l,r]��r
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
	//������������� 1.�������� 2.�Ҷ������ 3.������ұ߽�+�Ҷ�����߽���� ֮һ 
	tree[rt].ml=max(max(tree[rt<<1].ml,tree[rt<<1|1].ml),tree[rt<<1].rl+tree[rt<<1|1].ll);
	tree[rt].ll=tree[rt<<1].ll;//�����Ϊ������󳤣���������������䣬��Ҫ���Ҷ����� 
	if(tree[rt].ll==(l+r)/2-l+1) tree[rt].ll+=tree[rt<<1|1].ll;
	tree[rt].rl=tree[rt<<1|1].rl;//����ҳ�ͬ�� 
	if(tree[rt].rl==r-(l+r)/2) tree[rt].rl+=tree[rt<<1].rl;
}
int query(int x,int l,int r,int rt)
{
	//Ҷ�ӽ�� �� ��ȫ���� �� ��ȫ������ ֱ�ӷ��� 
	if(l==r||tree[rt].ml==r-l+1||!tree[rt].ml) return tree[rt].ml;
	if(x<(l+r)/2+1-tree[rt<<1].rl) return query(x,l,(l+r)/2,rt<<1);//���м�ش���� 
	if(x>(l+r)/2+tree[rt<<1|1].ll) return query(x,(l+r)/2+1,r,rt<<1|1);//���м�ش��Ҳ� 
	return tree[rt<<1].rl+tree[rt<<1|1].ll;//���м�ش�ֱ�ӷ��ؼӺ� 
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