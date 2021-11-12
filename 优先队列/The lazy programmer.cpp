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
//̰�ļ����ȶ���ά��
/*
˼·���Ȱ��������ս���֮������Ȼ���������ÿһ�����񣬼�����������޷����
      ��ô��ǰ�棨����������������ҵ�a�������������ܹ��ٸ���Ǯ��ǰ�ᣩ��
      ��Ǯ����ڳ�ʱ������ϵ�ǰ������񣬶�����ܹ������ȶ���ά��
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
			    f[i].money=0;   //�Ѿ�����������Ǯ
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
				double temp=(double)(day-f[i].d)/cur.a; //������������Ҫ��cur�����Ǯ
				if(temp+cur.money<=(double)cur.b/cur.a)   //�������Ǯ�����Ѿ�����ǮС���ܹ�������Ǯ
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