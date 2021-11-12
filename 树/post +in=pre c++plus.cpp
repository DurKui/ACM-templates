#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <list>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const double Pi = acos(-1.0);
const long double eps = 1e-6;
#define mem(a,x) memset(a,x,sizeof a)
#define ll long long
//#define For(i,a,b) for (int i = a; i <= b; ++i)
//#define rush() int T;scanf("%d", &T);for(int Ti=1;Ti<=T;Ti++)
//#define scd(x) scanf("%d", &x)
//#define scl(x) scanf("%lld", &x)
//#define scdd(x,y) scanf("%d %d", &x, &y)
//#ifndef
//#define
//#endif
ll in[10005];
ll post[10005];
ll n;
class node{
public:
node* l=NULL,*r=NULL;
ll data;
void build(int n1,int n2,int m1,int m2);
void print();
};
void node::build(int n1,int n2,int m1,int m2){
   ll k=-1;
      data=post[m2];
       for(ll i=n1;i<=n2;i++)
       {
          if(in[i]==post[m2]) {
               k=i;
               break;          
          }
       }

   if(k!=n1) {l=new node;l->build(n1,k-1,m1,k-1+m2-n2);}
   if(k!=n2){r=new node;r->build(k+1,n2,k+m2-n2,m2-1);}
}
void node::print(){
   cout<<" "<<data;
   if(l!=NULL) l->print();
   if(r!=NULL) r->print();
}
int main()
{  cin>>n;
   node p;
   for(ll i=1;i<=n;i++)
   cin>>post[i];
   for(ll i=1;i<=n;i++)
   cin>>in[i];
   p.build(1,n,1,n);
   cout<<"Preorder:";
   p.print();
   return 0;
}