#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
#define eps 1e-8
//����������
//��x�̶�������������һ����������ôy�����ܳ���һ�����κ���������������
//ÿ��ѡ��һ��x���ҵ��ܳ���С��y��Ҳ�͵��ڰ�y�̶����������ڲ�ͬ��x������Ӧ��y�ǲ�һ���ģ����Ƕ���ÿ��x�������ҵ�һ��
//yʹѡ��ǰx�ܳ���С�����ڹ̶�y����ôx�����ܳ�Ҳʹ���κ�������ô������ȡx��ʱ��Ҳ�������ּ���
//���͵����������֣�ע����ʵ������
struct node{
	double x,y;
}a[11000];
int n;
double judge_(double x,double y)
{
	double ans=0;
	for(int i=1;i<=n;i++)
		ans+=sqrt((x-a[i].x)*(x-a[i].x)+(y-a[i].y)*(y-a[i].y));
	return ans;
} 
double judge(double x)
{
	double l=0,r=10000;
	double ans;
	while((r-l)>eps)
	{
		double m1=l+(r-l)/3;
		double m2=r-(r-l)/3;
		double s1=judge_(x,m1);
		double s2=judge_(x,m2); 
		if(s1<s2)
			r=m2,ans=s1;
		else
			l=m1,ans=s2;
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%lf%lf",&a[i].x,&a[i].y);
		double l=0,r=10000;
		double ans;
		while((r-l)>eps)
		{
			double m1=l+(r-l)/3;
			double m2=r-(r-l)/3;
			double s1=judge(m1);
			double s2=judge(m2); 
			if(s1<s2)
				r=m2,ans=s1;
			else
				l=m1,ans=s2;
		}
		printf("%.0f\n",(ans));
	return 0;
}