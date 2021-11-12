#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
#define ll long long
using namespace std;
//���ò��鼯�ж�û�л�·
//��ֻ��һ�����ڵ㣬������������������ͨ
ll ok;
ll s[100005];
ll vis[100005];
ll find(ll x)
{
    if(x!=s[x])
    {
        s[x]=find(s[x]);
    }
    return s[x];
}
void merge(ll x,ll y)
{
    ll xx=find(x);
    ll yy=find(y);
    if(xx!=yy)
    {
        s[xx]=yy;
    }
    else ok=1;
}
int main()
{
ll a,b;
while(~scanf("%lld%lld",&a,&b))
{
    if(a==0&&b==0) {printf("Yes\n");continue;}
    if(a==-1&&b==-1) break;
    for(ll i=0;i<100005;i++)
    {
    s[i]=i;
    vis[i]=0;
    }
    merge(a,b);
    vis[a]=1;
    vis[b]=1;
    ok=0;
    while(scanf("%lld%lld",&a,&b)&&a&&b)
    {
        merge(a,b);
        vis[a]=1;
        vis[b]=1;
    }
    if(ok==1) {
        printf("No\n");
        continue;
    }
    else 
    {
        ll cnt=0;
        for(ll i=0;i<100005;i++)
        {
            if(vis[i]&&s[i]==i)
            cnt++;
        }
        if(cnt==1) printf("Yes\n");
        else printf("No\n");
    }
}
    return 0;
}