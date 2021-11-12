#include <stdio.h>
#include<iostream>
#include<string.h>
#define ll long long
using namespace std;
const double eps = 1e-5;
const int INF = 0x7fffffff;
const int MOD = 1e9 + 7;
const int MAXN = 5e4 + 7;
//ö��+���ಢ�鼯
//��1ΪӮ�ô���ʯͷ��������0Ϊƽ�ּ�˫��Ϊͬһ���ͣ�2Ϊ�������ʯͷ������
//ע�����+3�ٶ�3ȡģ������-1��2����ͬ�Ľ����������
//Ȼ������Ȩֵ���鼯����ά��
//ö����������ÿ���˶��ǲ��У��������ì�ܣ�������˲��ǲ��У����л��ڵ��У���֮�����ǲ��У�ͳ�Ʋ�����
//�������1��not determined��==0��impossible
//�ڴ˹����зֱ��¼�Ҵ���Ǹ��ִ��У����ȷ��ִ��˲��ǲ��У��������ʱ�̣���ô���ʱ�̼�Ϊ�����ҵ�Ψһ���Ǹ����е�ʱ��
//��Ϊ���в��ǲ��е��˶��ҵ��ˣ��Ҷ���¼�������緢�ֵ�ֵ���ٴ���ȡ���ֵ����Ϊ�����ҵ�Ψһ���Ǹ����е�ʱ�̡�
int s[10005];
int sum[10005];
ll flag[10005];
ll index[10005];
struct node
{
    ll a,b;
    ll op;
}node[100005];
int find(int x){
   if(x!=s[x])
   {
       ll t=s[x];
       s[x]=find(s[x]);
       sum[x]=(sum[x]+sum[t]+3)%3;
   }
   return s[x];
}
int main()
{
ll n,m;
while(~scanf("%lld%lld",&n,&m))
{
memset(flag,1,sizeof(flag));
memset(index,0,sizeof(index));
for(ll i=0;i<m;i++)
{
   ll a,b;
   char op;
   scanf("%lld%c%lld",&a,&op,&b);
    if(op=='>') node[i].op=1;
    else if(op=='=') node[i].op=0;
    else node[i].op=2;
    node[i].a=a;
    node[i].b=b;
}
for(ll i=0;i<n;i++)
{
    for(ll j=0;j<=n;j++){
    s[j]=j;
    sum[j]=0;
    }
    for(ll j=0;j<m;j++)
    {
        if(node[j].a==i||node[j].b==i) continue;
        ll x=find(node[j].a);
        ll y=find(node[j].b);
        if(x!=y)
        {
            s[x]=y;
            sum[x]=(sum[node[j].b]-sum[node[j].a]+node[j].op+3)%3;
        }
        else 
        {
            if(node[j].op!=(sum[node[j].a]-sum[node[j].b]+3)%3)
            {
                flag[i]=0;
                index[i]=j+1;
                break;
            }
        }
    }
}
ll ans=0;
ll mm=0;
ll maxx=0;
for(ll i=0;i<n;i++)
{
    if(flag[i])
    {
        ans++;
        mm=i;
    }
    else maxx=max(maxx,index[i]);
}
if(ans==1) printf("Player %lld can be determined to be the judge after %lld lines\n",mm,maxx);
else if(ans==0) printf("Impossible\n");
else if(ans>1)printf("Can not determine\n");
}
    return 0;
}