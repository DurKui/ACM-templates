#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<map>
using namespace std;
//贪心加优先队列维护
/*
思路：先把任务依照结束之间排序，然后依次完毕每一个任务，假设这个任务无法完毕
      那么在前面（包含这个）任务中找到a属性最大的任务（能够再给他钱的前提），
      给钱这个腾出时间来完毕当前这个任务，而这个能够用优先队列维护
*/
#define INF 0x3f3f3f3f
#define N 100005
 struct stud{
  int a,b,d;
  double money;
  bool operator<(const stud b) const
  {
  	return a<b.a;
  }
}f[N]; 
int cmp(stud x,stud y)
{
	return x.d<y.d;
}
priority_queue<stud>q;
int n;

int main()
{
	int i,j;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
			{
				scanf("%d%d%d",&f[i].a,&f[i].b,&f[i].d);
			    f[i].money=0;   //已经给这个任务的钱
			}
	    sort(f,f+n,cmp);
	    while(!q.empty()) q.pop();
	    double ans,day;
	    ans=day=0;
	    stud cur;
	    for(i=0;i<n;i++)
		{
			q.push(f[i]);
			day+=f[i].b;
			while(day>f[i].d)
			{
				cur=q.top();
				q.pop();
				double temp=(double)(day-f[i].d)/cur.a; //完毕这个任务须要给cur任务的钱
				if(temp+cur.money<=(double)cur.b/cur.a)   //假设这个钱加上已经给的钱小于能够给他的钱
				{
					day-=temp*cur.a;
					cur.money+=temp;
					ans+=temp;
					q.push(cur);
					break;
				}
				else
				{
					temp=((double)cur.b/cur.a-cur.money);
					day-=temp*cur.a;
					ans+=temp;
				}
			}
		}
 
		printf("%.2f\n",ans);
	}
  return 0;
}