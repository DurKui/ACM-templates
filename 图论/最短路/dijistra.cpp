#include<bits/stdc++.h>
#define ll long long
const int INF=1e6;
const int NUM=105;
using namespace std;
struct edge{
    ll from,to,w;
    edge(ll a,ll b,ll c){from=a,to=b,w=c;}
};
vector<edge>e[NUM];
struct node
{
    ll id,dis;
    node(ll b,ll c){id=b,dis=c;}
    bool operator<(const node &a)const
    {
        return dis<a.dis;
    }
};
ll n,m;
void dij()
{ll s=1;
ll dis[NUM];
bool done[NUM];
for(ll i=1;i<=n;i++)
{
    dis[i]=INF;
    done[i]=false;
}
dis[s]=0;
priority_queue<node>q;
q.push(node(s,dis[s]));
while(!q.empty())
{
    node ss=q.top();
    q.pop();
    if(done[ss.id])
    continue;
    done[ss.id]=true;
    for(ll i=0;i<e[ss.id].size();i++)
    {
        edge y=e[ss.id][i];
        if(done[y.to]) continue;
        if(dis[y.to]>ss.dis+y.w)
        {
            dis[y.to]=ss.dis+y.w;
            q.push(node(y.to,dis[y.to]));
        }
    }
}
}

int main(){
while(cin>>n>>m)
{
    if(n==0&&m==0) return 0;
    for(ll i=1;i<=n;i++)
    e[i].clear();
    while(m--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        e[a].push_back(edge(a,b,c));
        e[b].push_back(edge(b,a,c));
    }
    dij();
}
    return 0;
}