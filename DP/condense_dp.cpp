#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//״̬ѹ��dp
/*���⣺
��n�ſγ���ҵ��ÿ����ҵ�Ľ�ֹʱ��ΪD,��Ҫ���ѵ�ʱ��ΪC������ҵ���ܰ�ʱ��ɣ�ÿ����1���1�֡�
��n����ҵ���γ̵��ֵ����Ⱥ�����
�������n����ҵ����Ҫ�۶��ٷ֣�������۷����ٵ�����ҵ˳��
PS:�ﵽ�۷����ٵķ����ж��֣�������ֵ�����С����һ�鷽��
������
n<=15��������֪��ֻ�����n����ҵ����ȫ���У�ѡ���۷����ٵļ��ɡ�
��һ�����������洢��n����ҵ������������1.������n����ҵ״���ֱ�
��Ӧ���������ĵ�0��1.��������,n-1λ�������⣬����������Ϊ2^n-1
���� 2^n-1��Ϊn����ҵȫ����ɣ�0Ϊû����ҵ��ɡ�����
��dp[i]��¼�����ҵ״̬Ϊiʱ����Ϣ������ʱ�䣬ǰһ��״̬��������ʧ�ķ�������
������������
1.״̬a������i����ҵ��������a����ҵi��δ��ɣ���a&i=0��
2.��������״̬dp[a],dp[b]���ܵ���dp[i],��ôѡ����ʹ����i�۷�С����һ��·������������ͬ��ת��3
3.������״̬�۵ķ�����ͬ����ôѡ���ֵ���С�ģ�������ҵ���ֵ������룬//�ʼ�dp[i].pre = min(a,b);
��ʼ����dp[0].cost = 0;dp[0].pre=-1;dp[0].reduced = 0;
���dp[2^n-1].reduced��Ϊ���ٿ۷֣��γ̰��ſɵݹ�����
*/
ll vis[100005];
struct node
{
    ll cost;
    ll reduce=0;
    ll pre;
    string name;
}dp[100005];
struct sub{
string name;
ll deadline;
ll cost;
}s[105];
void print(ll x)
{
    if(x<=0) return ;
    print(dp[x].pre);
    cout<<dp[x].name<<endl;
}
int main()
{
IOS
ll t;
cin>>t;
while(t--)
{
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        cin>>s[i].name>>s[i].deadline>>s[i].cost;
    }
    memset(vis,0,sizeof(vis));
    ll up=pow(2,n)-1;
    dp[0].cost=0;
   // dp[0].pre=-1;
    dp[0].reduce=0;
    vis[0]=1;
    for(ll i=0;i<up;i++)
    {
        for(ll j=0;j<n;j++)
        {
            ll p=1<<j;
            if((i&p)==0)
            {
                ll next=i|p;
                ll tmp=dp[i].cost+s[j].cost;
                dp[next].cost=tmp;
                ll red=tmp-s[j].deadline;
                if(red<0) red=0;
                red+=dp[i].reduce;
                if(vis[next])
                {
                    if(dp[next].reduce>red)
                    {
                        dp[next].reduce=red;
                        dp[next].pre=i;
                        dp[next].name=s[j].name;
                    }
                   
                }
                 else 
                    {   vis[next]=1;
                        dp[next].pre=i;
                        dp[next].reduce=red;
                          dp[next].name=s[j].name;

                    }
            }
        }
    }

    cout<<dp[up].reduce<<endl;
    print(up);
}

return 0;
}