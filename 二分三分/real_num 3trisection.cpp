#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
#define eps 1e-8
//三分套三分
//将x固定下来，即当作一个常数，那么y关于总长是一个二次函数，可以用三分
//每次选择一个x，找到总长最小的y，也就等于把y固定下来，对于不同的x，所对应的y是不一样的，但是对于每个x都可以找到一个
//y使选择当前x总长最小，等于固定y，那么x关于总长也使二次函数，那么在外面取x的时候也对其三分即可
//典型的三分套三分，注意是实数三分
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