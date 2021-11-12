#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
 //树状数组维护前缀和的灵活运用
 //题意：给定一个数列，找出有多少对i与j满足i<j且a[i]>=j且a[j]>=i
 //思路：先找满足a[j]>=i的数，一个n大小的数列，下标最大也只是为n，所以先将数组从小到大排序
 //依次从小到大取a[i]，令k=min(n,a[i]);
 //再从原序列找下标比k小的数，利用树状数组的前缀和+1，再利用树状数组的求和找出比p[i].num即p[i]原下标大的数量
 //注意要减掉自己包括在其中的情况
 //最后除以2即对数
struct node
{
	int num;
	int sum;
} p[maxn],q[maxn];
 
int n;
long long sum[maxn];
 
bool cmp(node a,node b)
{
	return a.sum< b.sum;
}
 
int lowbit(int x)
{
	return x&(-x);
}
 
void add(int x,int val)
{
	for(int i = x;i<= n;i+= lowbit(i))
		sum[i]++;
}
 
long long get_sum(int x)
{
	long long ans = 0;
	for(int i = x;i>= 1;i-= lowbit(i))
		ans+= sum[i];
	return ans;
}
 
int main()
{
	cin>>n;
	
	for(int i = 1;i<= n;i++)
	{
		scanf("%d",&p[i].sum);
		p[i].num = i;
		q[i] = p[i];
	}
	
	sort(p+1,p+n+1,cmp);
	
	long long ans = 0;
	int j = 1;
	for(int i = 1;i<= n;i++)
	{
		int k = min(n,p[i].sum);
		for(;j<= k;j++){
			add(min(q[j].sum,n),1);
        }
         cout<<sum[3]<<endl;
		ans+= get_sum(n)-get_sum(p[i].num-1); //查询大于等于p[i].num的有多少 
		memset(sum,0,sizeof(sum));
		if(p[i].num<= p[i].sum)//记得把自己去掉 
			ans--;
            //cout<<ans<<endl;
	}
	
	cout<<ans/2<<endl;
	
	return 0;
}
