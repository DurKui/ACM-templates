#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
 //��״����ά��ǰ׺�͵��������
 //���⣺����һ�����У��ҳ��ж��ٶ�i��j����i<j��a[i]>=j��a[j]>=i
 //˼·����������a[j]>=i������һ��n��С�����У��±����Ҳֻ��Ϊn�������Ƚ������С��������
 //���δ�С����ȡa[i]����k=min(n,a[i]);
 //�ٴ�ԭ�������±��kС������������״�����ǰ׺��+1����������״���������ҳ���p[i].num��p[i]ԭ�±�������
 //ע��Ҫ�����Լ����������е����
 //������2������
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
		ans+= get_sum(n)-get_sum(p[i].num-1); //��ѯ���ڵ���p[i].num���ж��� 
		memset(sum,0,sizeof(sum));
		if(p[i].num<= p[i].sum)//�ǵð��Լ�ȥ�� 
			ans--;
            //cout<<ans<<endl;
	}
	
	cout<<ans/2<<endl;
	
	return 0;
}
