#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//状态压缩dp
/*大意：
有n门课程作业，每门作业的截止时间为D,需要花费的时间为C，若作业不能按时完成，每超期1天扣1分。
这n门作业按课程的字典序先后输入
问完成这n门作业至少要扣多少分，并输出扣分最少的做作业顺序
PS:达到扣分最少的方案有多种，请输出字典序最小的那一组方案
分析：
n<=15，由题意知，只需对这n份作业进行全排列，选出扣分最少的即可。
用一个二进制数存储这n份作业的完成情况，第1.。。。n个作业状况分别
对应二进制数的第0，1.。。。。,n-1位则由题意，故数字上限为2^n-1
其中 2^n-1即为n项作业全部完成，0为没有作业完成。。。
用dp[i]记录完成作业状态为i时的信息（所需时间，前一个状态，最少损失的分数）。
递推条件如下
1.状态a能做第i号作业的条件是a中作业i尚未完成，即a&i=0。
2.若有两个状态dp[a],dp[b]都能到达dp[i],那么选择能使到达i扣分小的那一条路径，若分数相同，转入3
3.这两种状态扣的分数相同，那么选择字典序小的，由于作业按字典序输入，//故即dp[i].pre = min(a,b);
初始化：dp[0].cost = 0;dp[0].pre=-1;dp[0].reduced = 0;
最后dp[2^n-1].reduced即为最少扣分，课程安排可递归的输出
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