#include<bits/stdc++.h>
#define ll long long 
using namespace std;
//������ʽǰ���ǵ�spfa
struct edge{
    ll to ,next,w;
}e[100005];
ll head[10005];
ll cnt=0,n,m;
ll dis[100005];
bool flag[10005];
ll neg[10005];
ll pre[10005];
void Init()
{
    for(ll i=0;i<10005;i++)
    {
        e[i].next=-1;
        head[i]=-1;
    }
cnt=0;
}
void add(ll u,ll v,ll w)
{
    e[cnt].to=v;
    e[cnt].w=w;
    e[cnt].next=head[u];
    head[u]=cnt++;
}
//��ʽǰ����
ll spfa(ll s)
{
    memset(neg,0,sizeof(neg));//�жϸ�Ȧ
    neg[s]=1;
    for(ll i=1;i<=n;i++){
        dis[i]=1200005;
        flag[i]=false;//���ĳһ�����ڲ��ڶ����У������ظ����
    }
    dis[s]=0;
    queue<ll> q;
    q.push(s);
    flag[s]=1;
    while(!q.empty())//ֱ������Ϊ��
    {
        ll u=q.front();
        q.pop();
        flag[u]=false;
        for(ll i=head[u];~i;i=e[i].next)//��u���ڵĶ���
        {
            ll v=e[i].to;
            ll w=e[i].w;
            if(dis[v]>dis[u]+w)//���и��µĶ����Ҳ��ڶ����еĶ������
            {
                dis[v]=w+dis[u];
                if(!flag[v]){
                flag[v]=true;
                q.push(v);
                neg[v]++;
                if(neg[v]>n) return 1;//�жϸ�Ȧ
                }
            }
        }
    }
}
int main()
{
while(cin>>n>>m)
{
    Init();
    if(n==0&&m==0) return 0;
    while(m--)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
    spfa(1);
}
    return 0;
}